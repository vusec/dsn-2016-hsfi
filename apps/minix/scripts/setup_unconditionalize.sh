#!/bin/bash

set -e

# directories
LROOT="$1"
MROOT="$LROOT/apps/minix"

[ ! -f "$MROOT/autosetup-paths.inc" ] || source "$MROOT/autosetup-paths.inc"

: ${PATHTOOLS:="$LROOT/autosetup.dir/install"}
: ${PATHQEMU:="$PATHTOOLS/bin/qemu-system-x86_64"}

# script settings
: ${DONT_BUILD_MINIX:=0} # boolean, skip configure.llvm
: ${NODEFAULTS:=0}       # boolean, assume CONFIGOPTS, RELINKOPTS and BUILDOPTS are pre-initialized
: ${LOGFILE="$MROOT/unconditionalize.setup.log"} # string, location of log file
: ${ONLY_BUILD_MINIX:=0} # boolean, skip configure.llvm
: ${REBUILDGOLD:=0}      # boolean, force rebuild of gold plugin

if [ "$NODEFAULTS" -eq 0 ]; then
	: ${BUILDOPTS:="edfi -fault-one-per-block -fault-rand-reseed-per-function=1 -fault-unconditionalize -inline-profiling unconditionalize.di"} # string, options for build.llvm
	: ${CONFIGOPTS:=edfi}    # string, options for configure.llvm
	: ${RELINKOPTS:=edfi}    # string, options for relink.llvm
fi

# settings passed to other scripts
export BUILDVARS
export C
export DI_PASS_ARGS
export HOME_SIZE
export HYPER
export JOBS
export GEN_GOLD_PLUGIN
export GENERATE_MAP
export MEMSIZE
export MINIXBRANCH
export REBUILD_MINIX
export ROOT_SIZE
export USR_SIZE
: ${BUILDVARS:="-V DBG=-g"}
: ${C:="kernel,servers,fs,net,drivers"}
: ${DI_PASS_ARGS:=} # possible option: -debug
: ${HYPER:="$PATHQEMU --enable-kvm"}
: ${JOBS:=16}
: ${MEMSIZE:=3072}
: ${MINIXBRANCH:=llvm_squashed_hsfi}
: ${ROOT_SIZE:=1048576}
: ${USR_SIZE:=8388608}

cd "$MROOT"
echo -n > "$LOGFILE"

# remove distributed recovery settings
rm -f "$LROOT/common.overrides.distrecovery.inc"

# build MINIX
if [ "$DONT_BUILD_MINIX" -eq 0 ]; then
	echo "Building MINIX..." | tee -a "$LOGFILE"
	cd "$MROOT"
	if [ "$REBUILDGOLD" -ne 0 -a -f "$MROOT/minix/minix/llvm/.gold_generated" ]; then
		rm "$MROOT/minix/minix/llvm/.gold_generated"
	fi
	./configure.llvm $CONFIGOPTS >> "$LOGFILE" 2>&1 
	echo "		[ done ] " | tee -a "$LOGFILE"

	[ "$ONLY_BUILD_MINIX" -eq 0 ] || exit 0
fi

# build LLVM-APPS
echo "Building LLVM-apps..." | tee -a "$LOGFILE"
cd "$MROOT"
make -C "$LROOT/llvm/di-passes/unconditionalize" install >> "$LOGFILE" 2>&1
make -C "$LROOT/llvm/passes/edfi" install >> "$LOGFILE" 2>&1
make -C "$LROOT/llvm/passes/sectionify" install >> "$LOGFILE" 2>&1
make -C "$LROOT/llvm/static/edfi" install >> "$LOGFILE" 2>&1
make -C "$LROOT/llvm/tools/di" install >> "$LOGFILE" 2>&1
echo "		[ done ] " | tee -a "$LOGFILE"

# EDFI relink
echo "Adding EDFI static libraries..." | tee -a "$LOGFILE"
cd "$MROOT"
./relink.llvm $RELINKOPTS >> "$LOGFILE" 2>&1
echo "		[ done ] " | tee -a "$LOGFILE"

# EDFI build
echo "Performing EDFI pass..." | tee -a "$LOGFILE"
cd "$MROOT"
./build.llvm $BUILDOPTS >> "$LOGFILE" 2>&1
echo "		[ done ] " | tee -a "$LOGFILE"

# build MINIX image
cd "$MROOT"
echo "Creating MINIX image" | tee -a "$LOGFILE"
./clientctl buildimage >> "$LOGFILE" 2>&1
echo "		[ done ] " | tee -a "$LOGFILE"

echo "Finished." | tee -a "$LOGFILE"
