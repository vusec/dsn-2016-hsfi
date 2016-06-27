#!/bin/bash

set -e

# expected to be defined by parent script:
# - INJECTFAULTS
# - PATHAPP
# - PRUNSCRIPTNAME
# - RUNNAMEFAULTY
# - RUNNAMEGOLDEN
# - SETTINGSNAME

if [ ! -f "$PATHAPP/prun-scripts/edfi-common.inc" ]; then
	echo "PATHAPP set incorrectly (PATHAPP=\"$PATHAPP\")" >&2
	exit 1
fi
[ ! -f "$PATHAPP/autosetup-paths.inc" ] || source "$PATHAPP/autosetup-paths.inc"

# script settings
: ${MEMSIZE:=3072}
: ${PRUNITER:=1}       # integer, how often to invoke prun
: ${PRUNOPTS:=""}      # string, options to specify to prun (like "-t 30:00" to extend reservation duration)
: ${PRUNNODES:=1}      # integer, number of nodes to use with prun
: ${TIMEOUTSEC:=900}   # integer, seconds after which to time out the run
: ${PRUNPERNODE:=1}    # integer, number of instances per node with prun
: ${REBUILDGUEST:=1}   # boolean, non-zero means rebuild guest binaries

# script settings for fault selection (not needed otherwise)
: ${NUMFAULTS:=10000}  # integer, number of faults to inject; used only in the first run after the golden run

# path specifications
: ${PATHROOT:="$PATHAPP/../.."}
: ${PATHOBJ:="$PATHAPP/src"}
: ${PATHGUESTBIN:="$PATHAPP/guestbin"}
: ${PATHMAPEXT:=.bc.map}
: ${PATHUCPATCHEXT:=.ucpatch}

: ${PATHSETTINGSBIN:="$PATHAPP/bin/$SETTINGSNAME"}
: ${PATHSETTINGSBINLOGS:="$PATHSETTINGSBIN/buildlogs"}
: ${PATHVMIMG:="$PATHROOT/autosetup.dir/vms/ubuntu-13.10.qcow2"}
: ${PATHVMIMGTYPE:=qcow2}

: ${PATHTEMPBASE="/local/$USER"}

: ${PATHTOOLS:="$PATHROOT/autosetup.dir/install"}
: ${PATHQEMU:="$PATHTOOLS/bin/qemu-system-x86_64"}
: ${PATHQEMUIMG:="$PATHTOOLS/bin/qemu-img"}
: ${HYPER:="$PATHQEMU --enable-kvm"}

: ${PATHOUTBASE:="$PATHROOT/results/linux"}
: ${PATHOUT:="$PATHOUTBASE/faulty-$RUNNAMEFAULTY-`date '+%Y%m%d-%H%M%S'`"}
: ${PATHGOLDEN:="$PATHOUTBASE/golden-$RUNNAMEGOLDEN"}

: ${PATHSELFAULTS:="$PATHAPP/selected-faults-$RUNNAMEGOLDEN.txt"}
: ${PATHSELTESTINDEX:="$PATHAPP/selected-test-index-$RUNNAMEFAULTY.txt"}
: ${PRUNSCRIPT:="$PATHAPP/prun-scripts/$PRUNSCRIPTNAME"}

: ${MINIXREPOSITORY:=https://github.com/vusec/minix-llvm.git}
: ${MINIXBRANCH:=llvm_squashed_hsfi}

if [ -z "$RUNNAMEFAULTY" ]; then
	echo "RUNNAMEFAULTY set incorrectly (RUNNAMEFAULTY=\"$RUNNAMEFAULTY\")" >&2
	exit 1
fi
if [ -z "$RUNNAMEGOLDEN" ]; then
	echo "RUNNAMEGOLDEN set incorrectly (RUNNAMEGOLDEN=\"$RUNNAMEGOLDEN\")" >&2
	exit 1
fi
if [ -z "$SETTINGSNAME" ]; then
	echo "SETTINGSNAME set incorrectly (SETTINGSNAME=\"$SETTINGSNAME\")" >&2
	exit 1
fi
if [ ! -f "$PATHVMIMG" ]; then
	echo "PATHVMIMG set incorrectly or VM image not downloaded by autosetup (PATHVMIMG=\"$PATHVMIMG\")" >&2
	exit 1
fi
if [ ! -x "$PATHQEMU" ]; then
	echo "PATHQEMU or PATHTOOLS set incorrectly or QEMU not built by autosetup (PATHQEMU=\"$PATHQEMU\")" >&2
	exit 1
fi
if [ ! -x "$PATHQEMUIMG" ]; then
	echo "PATHQEMUIMG or PATHTOOLS set incorrectly or QEMU not built by autosetup (PATHQEMUIMG=\"$PATHQEMUIMG\")" >&2
	exit 1
fi
if [ ! -x "$PRUNSCRIPT" ]; then
	echo "PRUNSCRIPT set incorrectly (PRUNSCRIPT=\"$PRUNSCRIPT\")" >&2
	exit 1
fi
if [ "$INJECTFAULTS" -eq 0 ]; then
	echo "Fault injection disabled"
	GOLDENRUN=0
elif [ ! -s "$PATHSELFAULTS" -a ! -d "$PATHGOLDEN" ]; then
	echo "Performing golden run"
	GOLDENRUN=1
else
	echo "Performing faulty run"
	GOLDENRUN=0
fi
if [ "$GOLDENRUN" -ne 0 -a "$INLINEPROFILING" -eq 0 ]; then
	echo "INLINEPROFILING must be set on golden run" >&2
	exit 1
fi

# other initialization
faultcount=0

common_print_settings()
{
	echo "Running EDFI experiment with the following settings:"
	echo "- HYPER           = $HYPER"
	echo "- NUMFAULTS       = $NUMFAULTS"
	echo "- PATHOUT         = $PATHOUT"
	echo "- PATHSETTINGSBIN = $PATHSETTINGSBIN"
	echo "- PATHTEMPBASE    = $PATHTEMPBASE"
	echo "- PATHVMIMG       = $PATHVMIMG"
	echo "- PRUNITER        = $PRUNITER"
	echo "- PRUNOPTS        = $PRUNOPTS"
	echo "- PRUNNODES       = $PRUNNODES"
	echo "- PRUNPERNODE     = $PRUNPERNODE"
	echo "- PRUNSCRIPT      = $PRUNSCRIPT"
	echo "- TIMEOUTSEC      = $TIMEOUTSEC"
}

common_must_build()
{
	[ ! -f "$PATHSETTINGSBIN/done" ]
}

common_cleanup()
{
	echo "Cleaning up"
	rm -rf "$PATHSETTINGSBIN"
	find "$PATHOBJ" -name "*$PATHMAPEXT" -type f -print0 | xargs -0 rm -f
	find "$PATHOBJ" -name "*$PATHUCPATCHEXT" -type f -print0 | xargs -0 rm -f
}

common_guest_bin()
{
	[ "$REBUILDGUEST" -ne 0 ] || exit
	rm -rf "$PATHGUESTBIN"

	echo "Fetching source for guest binaries"
	mkdir -p "$PATHGUESTBIN/src"
	[ -d  "$PATHGUESTBIN/src/minix/.git" ] || git clone -b "$MINIXBRANCH" --depth 1 "$MINIXREPOSITORY" "$PATHGUESTBIN/src/minix"
	mkdir -p "$PATHGUESTBIN/src/hypermemclient"
	cp "$PATHROOT/llvm/tools/hypermemclient/"{Makefile,*.c,*.h} "$PATHGUESTBIN/src/hypermemclient"

	echo "Building MINIX test set guest binaries"
	( cd "$PATHGUESTBIN/src/minix/minix/tests" && ./linux-compile.sh )
	mkdir -p "$PATHGUESTBIN/bin/tests"
	cp -r "$PATHGUESTBIN/src/minix/minix/tests/linux-bin"/* "$PATHGUESTBIN/bin/tests"

	echo "Building unixbench guest binaries"
	( cd "$PATHGUESTBIN/src/minix/minix/benchmarks/unixbench-5.1.2" && ./linux-compile.sh )
	mkdir -p "$PATHGUESTBIN/bin/benchmarks"
	cp -r "$PATHGUESTBIN/src/minix/minix/benchmarks/unixbench-5.1.2/linux-bin"/* "$PATHGUESTBIN/bin/benchmarks"

	echo "Building hypermemclient guest binaries"
	make -C "$PATHGUESTBIN/src/hypermemclient" CFLAGS=-m32
	mkdir -p "$PATHGUESTBIN/bin/hypermemclient"
	cp "$PATHGUESTBIN/src/hypermemclient/hyper" "$PATHGUESTBIN/bin/hypermemclient"
}

common_prepare_pathout()
{
	echo "Writing output to $PATHOUT"
	mkdir -p "$PATHOUTBASE"
	mkdir "$PATHOUT"
	set > "$PATHOUT/settings.txt"
	cp -r "$PATHSETTINGSBINLOGS" "$PATHOUT"
	cp -r "$PATHSETTINGSBIN/maps" "$PATHOUT"
	cp -r "$PATHSETTINGSBIN/ucpatch" "$PATHOUT"
	ln -s "$PATHSETTINGSBIN" "$PATHOUT/bin"
}

common_build_done()
{
	mkdir -p "$PATHSETTINGSBIN/binaries/arch/x86"
	mv "$PATHOBJ/vmlinux" "$PATHSETTINGSBIN/binaries"
	cp -r "$PATHOBJ/arch/x86/boot" "$PATHSETTINGSBIN/binaries/arch/x86"

	mkdir -p "$PATHSETTINGSBIN/maps"
	mv `find "$PATHOBJ" -name "*$PATHMAPEXT" -type f` "$PATHSETTINGSBIN/maps" || true

	mkdir -p "$PATHSETTINGSBIN/modules"
	mv "$PATHOBJ/arch/x86/boot/bzImage" "$PATHSETTINGSBIN/modules"

	mkdir -p "$PATHSETTINGSBIN/ucpatch"
	for f in `find "$PATHOBJ" -name "*$PATHUCPATCHEXT" -type f`; do
		mv "$f" "$PATHSETTINGSBIN/ucpatch"
	done

	mkdir -p "$PATHSETTINGSBINLOGS"

	touch "$PATHSETTINGSBIN/done"
}

common_select_faults()
{
	faultcount=0
	if [ ! -s "$PATHSELFAULTS" ]; then
		if [ -d "$PATHGOLDEN" ]; then
			echo "Selecting faults to inject based on the golden run in $PATHGOLDEN"
			make -C "$PATHROOT/llvm/tools/hypermemloganalyze/faultpicker" faultpicker
			"$PATHROOT/llvm/tools/hypermemloganalyze/faultpicker/faultpicker" -n "$NUMFAULTS" "$PATHGOLDEN/maps/.vmlinux.main.bc.map" "$PATHGOLDEN"/hypermemlog-*.txt > "$PATHSELFAULTS"
		fi
		rm -f "$PATHSELTESTINDEX"
	fi
	if [ -s "$PATHSELFAULTS" ]; then
		echo "Using faults specified in $PATHSELFAULTS for faulty run"
		faultcount="`wc -l "$PATHSELFAULTS" | cut -d" " -f1`"
		make -C "$PATHROOT/llvm/tools/unconditionalize-patch" unconditionalize-patch
	else
		echo "No faults have been selected, performing golden run"
	fi
	[ ! -s "$PATHSELFAULTS" ] || cp "$PATHSELFAULTS" "$PATHOUT"
}

common_check_map()
{
	if [ -d "$PATHGOLDEN" ]; then
		mapfiles="`find "$PATHGOLDEN/maps" "$PATHOUT/maps" -name "*.map" | sed 's,.*/,,' | sort | uniq`"
		badmap=0
		for f in $mapfiles; do
			if ! diff "$PATHGOLDEN/maps/$f" "$PATHOUT/maps/$f"; then
				echo "Map file $f differs between $PATHGOLDEN/maps and $PATHOUT/maps" >&2
				badmap=1
			fi
		done
		[ "$badmap" = 0 ]
	fi
}

common_prun()
{
	if which prun > /dev/null; then
		prun -export-env -np "$PRUNNODES" "-$PRUNPERNODE" -o "$OUTFILE" $PRUNOPTS "$PRUNSCRIPT"
	else
		# emulate parallel run functionality on the local system
		for node in `seq 1 "$PRUNNODES"`; do
			for instance in `seq 1 "$PRUNPERNODE"`; do
				PRUN_CPU_RANK="$node" "$PRUNSCRIPT" > "$OUTFILE.$node.$instance" 2>&1 &
			done
			wait
		done
	fi
}

common_run_experiment()
{
	echo "Starting experiments"

	# parameters needed by edfi-prun-common.inc
	export APPEND
	export BINARIESDIR="$PATHSETTINGSBIN/binaries"
	export HYPER
	export MEMSIZE
	export MODULEDIR="$PATHSETTINGSBIN/modules"
	export PATHAPP
	export PATHGUESTBIN
	export PATHOUT
	export PATHQEMUIMG
	export PATHROOT
	export PATHTEMPBASE
	export PATHVMIMG
	export PATHVMIMGTYPE
	export SELTESTINDEXFIRST
	export TIMEOUTSEC
	export UCPATCHDIR="$PATHSETTINGSBIN/ucpatch"

	# parameters possibly needed by $PRUNSCRIPT
	export PATHSELFAULTS

	cd "$PATHOUT"
	if [ -s "$PATHSELTESTINDEX" ]; then
		SELTESTINDEXFIRST="`cat "$PATHSELTESTINDEX"`"
	else
		SELTESTINDEXFIRST=1
	fi
	for iter in `seq 1 "$PRUNITER"`; do
		runcount="`expr "$PRUNNODES" \* "$PRUNPERNODE"`"
		if [ "$faultcount" -gt 0 ]; then 
			faultavail="`expr "$faultcount" - "$SELTESTINDEXFIRST" + 1`"
			if [ "$faultavail" -le 0 ]; then
				echo "No more faults available"
				break
			fi
			[ "$runcount" -le "$faultavail" ] || runcount="$faultavail"
		fi
		SELTESTINDEXLAST="`expr "$SELTESTINDEXFIRST" + "$runcount"`"
		echo "Starting experiments $SELTESTINDEXFIRST-`expr "$SELTESTINDEXLAST" - 1`"
		OUTFILE="qemu-out-$SELTESTINDEXFIRST" common_prun > "$PATHOUT/prun-out-$SELTESTINDEXFIRST.txt" 2>&1 || true

		SELTESTINDEXFIRST="$SELTESTINDEXLAST"
		echo "$SELTESTINDEXFIRST" > "$PATHSELTESTINDEX"
	done

	# if we did a golden run, rename the output directory to use it on the next invocation
	if [ "$GOLDENRUN" -ne 0 ]; then
		echo "Retaining golden run results as $PATHGOLDEN"
		mv "$PATHOUT" "$PATHGOLDEN"
		rm -f "$PATHSELTESTINDEX"
	fi

	echo "Completed succesfully"
}
