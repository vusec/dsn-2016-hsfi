#!/bin/sh
set -ex

export HYPER=/root/benchmark/hypermemclient/hyper

BENCHMARKSTEP="<<<BENCHMARKSTEP>>>"
if [ -n "$BENCHMARKSTEP" ]; then
	testfirst="`echo "$BENCHMARKSTEP" | cut -d- -f1`"
	testlast="`echo "$BENCHMARKSTEP" | cut -d- -f2`"
	for i in `seq 0 11`; do
		if [ "$i" -lt "$testfirst" -o "$i" -gt "$testlast" ]; then
			eval export "RUNS_$i=0"
		fi
	done
fi

cd /root/benchmark/benchmarks
./run_bc.sh || true
"$HYPER" quit || true
shutdown -P now
poweroff
