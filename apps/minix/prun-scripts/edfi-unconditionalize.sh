#!/bin/bash

set -e

# script settings (also see edfi-common.inc)
: ${BENCHMARK:=1} # 1=minix tests, 2=unixbench
: ${BENCHMARKSTEP:=""}
: ${INJECTFAULTS:=0} # boolean, non-zero means inject faults
: ${INJECTIONMODEL:=4} # 0=none, 1=traditional edfi, 4=unconditionalize
: ${INLINEPROFILING:=0} # boolean, non-zero means add inline profiling

# base directory
: ${PATHAPP:=""}
if [ -z "$PATHAPP" -a -f prun-scripts/edfi-common.inc ]; then
	PATHAPP="$PWD"
elif [ ! -f "$PATHAPP/prun-scripts/edfi-common.inc" ]; then
	echo "error: either run from llvm-apps/apps/minix or set PATHAPP to that directory" >&2
	exit 1
fi

# parameters to edfi-common.inc
: ${PRUNSCRIPTNAME:="edfi-prun-unconditionalize.sh"}
: ${SETTINGSNAME:="im$INJECTIONMODEL-pr$INLINEPROFILING"}
: ${RUNNAMEFAULTY:="uc-minix-bm$BENCHMARK-$SETTINGSNAME"}
: ${RUNNAMEGOLDEN:="uc-minix-bm$BENCHMARK"}

# include common functions/settings
. "$PATHAPP/prun-scripts/edfi-common.inc"

# parameters to setup_unconditionalize.sh
export BUILDOPTS
export CONFIGOPTS
export CROSS_TOOLS
export JOBS
export NODEFAULTS
export REBUILDGOLD
export RELINKOPTS
: ${BUILDOPTS:=""}
: ${CONFIGOPTS:=""}
: ${JOBS:=16}
: ${NODEFAULTS:=1}
: ${REBUILDGOLD:=0}
: ${RELINKOPTS:=""}

# apply injection model
export APPEND=""
if [ "$INJECTIONMODEL" -ne 0 ]; then
	CONFIGOPTS="$CONFIGOPTS edfi"
	RELINKOPTS="$RELINKOPTS edfi"
	BUILDOPTS="$BUILDOPTS edfi -fault-one-per-block -fault-rand-reseed-per-function=1"
fi
case "$INJECTIONMODEL" in
0)
	;;
1)
	;;
4)
	BUILDOPTS="$BUILDOPTS -fault-unconditionalize unconditionalize.di"
	;;
*)
	echo "Incorrect INJECTIONMODEL: $INJECTIONMODEL" &>2
	exit 1
	;;
esac
if [ "$INLINEPROFILING" -ne 0 ]; then
	BUILDOPTS="$BUILDOPTS -inline-profiling"
fi

# print settings
common_print_settings
echo "- BENCHMARK       = $BENCHMARK"
echo "- BENCHMARKSTEP   = $BENCHMARKSTEP"
echo "- INJECTIONMODEL  = $INJECTIONMODEL"
echo "- INLINEPROFILING = $INLINEPROFILING"

if common_must_build; then
	# clean up old files that might otherwise go stale
	common_cleanup
	rm -f "$PATHAPP/unconditionalize.setup.log"

	# instrument system
	cd "$PATHAPP"
	scripts/setup_unconditionalize.sh "$PATHROOT"

	# build MINIX VM image
	common_build_vm

	# copy built files to PATHSETTINGSBIN
	common_build_done
	mv "$PATHAPP/unconditionalize.setup.log" "$PATHSETTINGSBINLOGS"
fi

# prepare output directory
common_prepare_pathout

if [ "$INJECTFAULTS" -ne 0 ]; then
	# select faults/tests if needed
	common_select_faults

	# check map files with golden run
	common_check_map
fi

# run experiment
export BENCHMARK
export BENCHMARKSTEP
common_run_experiment
