#!/bin/sh
set -ex

cp -r /mnt/hypermemclient /root
make -C /root/hypermemclient clean all
export HYPER=/root/hypermemclient/hyper

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

cd /usr/benchmarks/unixbench
./run_bc || true
"$HYPER" quit || true
shutdown -pD now
poweroff
