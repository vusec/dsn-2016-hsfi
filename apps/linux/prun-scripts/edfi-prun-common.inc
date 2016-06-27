#!/bin/bash

set -e

# expected incoming parameters:
# - APPEND
# - BINARIESDIR
# - FAULTSPEC (only needed when common_run is invoked)
# - HYPER
# - MEMSIZE
# - MODULEDIR
# - PATHAPP
# - PATHGUESTBIN
# - PATHOUT
# - PATHQEMUIMG
# - PATHROOT
# - PATHTEMPBASE
# - PATHVMIMG
# - PATHVMIMGTYPE
# - PRUN_CPU_RANK (from prun)
# - SELTESTINDEXFIRST
# - TIMEOUTSEC
# - UCPATCHDIR

# paths
SELTESTINDEX="`expr "$SELTESTINDEXFIRST" + "${PRUN_CPU_RANK}"`"
PATHHYPERMEMLOG="$PATHOUT/hypermemlog-$SELTESTINDEX.txt"
PATHSERIALLOG="$PATHOUT/serial-$SELTESTINDEX.txt"
if mkdir -p "$PATHTEMPBASE" 2> /dev/null; then
	chmod 700 "$PATHTEMPBASE"
else
	PATHTEMPBASE=/tmp
fi
PATHTEMP="$PATHTEMPBASE/tmp-$SELTESTINDEX"
PATHDELTAIMG="$PATHTEMP/image_delta.qcow2"
PATHTESTIMGDIR="$PATHTEMP/image_test"
PATHTESTIMG="$PATHTESTIMGDIR/disk.tar"

rm -rf "$PATHTEMP"
mkdir -p "$PATHTEMP"
mkdir -p "$PATHTESTIMGDIR/files"

common_setup_disk_delta()
{
	# set up disk image for deltas from the primary disk (which is shared)
	echo "Creating delta disk image $PATHDELTAIMG for primary disk $PATHVMIMG"
	"$PATHQEMUIMG" create -f qcow2 -o "backing_file=$PATHVMIMG,backing_fmt=$PATHVMIMGTYPE" "$PATHDELTAIMG"
}

common_setup_disk_config()
{
	# set up secondary disk image for configuration
	echo "Creating secondary disk image"
	mkdir -p "$PATHTESTIMGDIR/files"
	cp -r "$PATHGUESTBIN/bin"/* "$PATHTESTIMGDIR/files"
	( cd "$PATHTESTIMGDIR/files" && tar -cf "$PATHTESTIMG" --owner=root --group=root * )
	size="`stat -c %s "$PATHTESTIMG"`"
	sizeround="`expr "$size" + 1048576 - "$size" % 1048576`"
	truncate -s "$sizeround" "$PATHTESTIMG"
}

common_run()
{
	# run the job
	echo "Starting QEMU for test $SELTESTINDEX"
	cd "$PATHAPP"

	MODULEDIRORIG="$MODULEDIR"
	if [ -n "$FAULTSPEC" ]; then
		rm -rf "$PATHTEMP/binaries"
		cp -r "$BINARIESDIR" "$PATHTEMP/binaries"
		PATHBOOTDIR="$PATHTEMP/binaries/arch/x86/boot" PATHBOOTDIR_I386="$PATHTEMP/binaries/arch/i386/boot" PATHMODORDER="$PATHTEMP/binaries/modules.order" PATHVMLINUX="$PATHTEMP/binaries/vmlinux" "$PATHAPP/build-bzImage.llvm"
		MODULEDIR="$PATHTEMP/binaries"
		"$PATHROOT/llvm/tools/unconditionalize-patch/unconditionalize-patch-helper.py" "$FAULTSPEC" "$MODULEDIR" "$UCPATCHDIR"
	fi

	APPEND="$APPEND cttyline=0"
	IMAGE="$PATHDELTAIMG"
	RUNARGS="-device hypermem,logpath=$PATHHYPERMEMLOG -hdb $PATHTESTIMG -serial file:$PATHSERIALLOG"

	echo "APPEND=$APPEND"
	echo "HYPER=$HYPER"
	echo "IMAGE=$IMAGE"
	echo "MEMSIZE=$MEMSIZE"
	echo "MODULEDIR=$MODULEDIRORIG"
	echo "MODULEDIR(temp)=$MODULEDIR"
	echo "RUNARGS=$RUNARGS"
	echo "TIMEOUTSEC=$TIMEOUTSEC"

	opts="$RUNARGS -m $MEMSIZE -hda $IMAGE -nographic"
	append="$APPEND debug console=tty0 console=ttyS0,115200n8 root=0801"
	timeout -k1 "$TIMEOUTSEC" $HYPER -kernel "$MODULEDIR/bzImage" -append "$append" $opts

	echo "Done with test $SELTESTINDEX"

	MODULEDIR="$MODULEDIRORIG"
}

common_cleanup()
{
	# delete temp files
	rm -rf "$PATHTEMP"
}
