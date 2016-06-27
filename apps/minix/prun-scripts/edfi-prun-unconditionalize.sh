#!/bin/bash

set -e

# expected incoming parameters (in addition to those in edfi-prun-common.inc):
# - BENCHMARK # 1=minix tests, 2=unixbench
# - BENCHMARKSTEP
# - PATHSELFAULTS

# parameters to edfi-prun-common.inc
export FAULTSPEC=""
export SELTESTINDEX="${PRUN_CPU_RANK}"

# include common functions/settings
. "$PATHAPP/prun-scripts/edfi-prun-common.inc"

# select faults
if [ -s "$PATHSELFAULTS" ]; then
	FAULTSPEC="`tail -n "+$SELTESTINDEX" "$PATHSELFAULTS" | head -n1`"
	echo "Faulty run, faultspec: $FAULTSPEC"
	if [ -z "$FAULTSPEC" ]; then
		echo "Empty faultspec (index=$SELTESTINDEX), aborting"
		exit 1
	fi
else
	FAULTSPEC=""
	echo "Golden run"
fi
echo "Fault to inject: $FAULTSPEC"

# set up boot script for VM
case "$BENCHMARK" in
1)
	cp "$PATHAPP/prun-scripts/edfi-prun-unconditionalize-boot-minixtest.sh" "$PATHTESTIMGDIR/files/boot.sh"
	;;
2)
	cp "$PATHAPP/prun-scripts/edfi-prun-unconditionalize-boot-unixbench.sh" "$PATHTESTIMGDIR/files/boot.sh"
	;;
*)
	echo "Incorrect benchmark selection $BENCHMARK" >&2
	exit 1
	;;
esac
sed -i "s/<<<BENCHMARKSTEP>>>/$BENCHMARKSTEP/g" "$PATHTESTIMGDIR/files/boot.sh"

# perform the experiment
common_setup_disk_delta
common_setup_disk_config
common_run
common_cleanup
