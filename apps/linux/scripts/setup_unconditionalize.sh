#!/bin/bash

set -e

# directories
LROOT="$1"
MROOT="$LROOT/apps/linux"

[ ! -f "$MROOT/autosetup-paths.inc" ] || source "$MROOT/autosetup-paths.inc"

: ${PATHTOOLS:="$LROOT/autosetup.dir/install"}
: ${PATHQEMU:="$PATHTOOLS/bin/qemu-system-x86_64"}

# script settings
: ${DONT_BUILD:=0}       # boolean, skip configure.llvm
: ${DISABLELTO:=0}       # boolean, disable LTO (see note below)
: ${NODEFAULTS:=0}       # boolean, assume CONFIGOPTS and BUILDOPTS are pre-initialized
: ${LOGFILE="$MROOT/unconditionalize.setup.log"} # string, location of log file
: ${ONLY_BUILD:=0}       # boolean, skip configure.llvm

# Unfortunately DISABLELTO does not work out-of-the-box as some Linux patches
# hard-code LTO linking. To build Linux without LTO, do the following:
# - in apps/linux/Makefile, add "false" as the first command for the
#   state/kernel-build target
# - in the root, run DISABLELTO=1 ./autosetup-linux.sh
# - git checkout -- apps/linux/Makefile
# - cd apps/linux/src
# - git checkout -- scripts/link-vmlinux.sh
# - in Makefile, remove "edfi/" as a dependency of "core-y"
# - cd ../../..
# - DISABLELTO=1 ./autosetup-linux.sh
# - do not invoke build.llvm when testing the rebuild time

export DISABLELTO
if [ "$DISABLELTO" -ne 0 ]; then
	BUILDOPTS=""
	CONFIGOPTS=""
elif [ "$NODEFAULTS" -eq 0 ]; then
	: ${BUILDOPTS:="edfi -fault-one-per-block -fault-rand-reseed-per-function=1 -fault-unconditionalize -inline-profiling unconditionalize.di"} # string, options for build.llvm
	: ${CONFIGOPTS:=edfi}    # string, options for configure.llvm
fi

# settings passed to other scripts
export DI_PASS_ARGS
export JOBS
: ${DI_PASS_ARGS:=} # possible option: -debug
: ${JOBS:=16}

cd "$MROOT"
echo -n > "$LOGFILE"

# remove distributed recovery settings
rm -f "$LROOT/common.overrides.distrecovery.inc"

# build LLVM-APPS
echo "Building LLVM-apps..." | tee -a "$LOGFILE"
cd "$MROOT"
make -C "$LROOT/llvm/di-passes/unconditionalize" install >> "$LOGFILE" 2>&1
make -C "$LROOT/llvm/passes/edfi" install >> "$LOGFILE" 2>&1
make -C "$LROOT/llvm/passes/sectionify" install >> "$LOGFILE" 2>&1
make -C "$LROOT/llvm/static/edfi" install >> "$LOGFILE" 2>&1
make -C "$LROOT/llvm/tools/di" install >> "$LOGFILE" 2>&1
echo "		[ done ] " | tee -a "$LOGFILE"

# build Linux
if [ "$DONT_BUILD" -eq 0 ]; then
	echo "Building Linux..." | tee -a "$LOGFILE"
	cd "$MROOT"
	./configure.llvm $CONFIGOPTS >> "$LOGFILE" 2>&1
	make -j "$JOBS" >> "$LOGFILE" 2>&1
	make install >> "$LOGFILE" 2>&1
	echo "		[ done ] " | tee -a "$LOGFILE"

	[ "$ONLY_BUILD" -eq 0 ] || exit 0
fi

# EDFI build
echo "Performing EDFI pass..." | tee -a "$LOGFILE"
cd "$MROOT"
NM=nm ./build.llvm $BUILDOPTS >> "$LOGFILE" 2>&1
echo "		[ done ] " | tee -a "$LOGFILE"

echo "Finished." | tee -a "$LOGFILE"
