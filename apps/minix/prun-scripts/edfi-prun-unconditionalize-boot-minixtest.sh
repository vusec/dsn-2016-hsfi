#!/bin/sh
set -ex

cp -r /mnt/hypermemclient /root
make -C /root/hypermemclient clean all
export HYPER=/root/hypermemclient/hyper

tests=" 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
       21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38    40
       41    43 44 45 46 47    49 50    52    54    56 57 58    60
       61    63       66 67 68 69 70 71       74 75    77 78    80
       81 82   "
BENCHMARKSTEP="<<<BENCHMARKSTEP>>>"
if [ -n "$BENCHMARKSTEP" ]; then
	testfirst="`echo "$BENCHMARKSTEP" | cut -d- -f1`"
	testlast="`echo "$BENCHMARKSTEP" | cut -d- -f2`"
	testsel=""
	for test in $tests; do
		if [ "$test" -ge "$testfirst" -a "$test" -le "$testlast" ]; then
			testsel="$testsel $test"
		fi
	done
	tests="$testsel"
fi

cd /usr/tests/minix-posix
QUICKTEST=yes INSTANTDEATH=yes ./run -t "$tests" -m < /dev/console || true # console redirection for test 3
"$HYPER" quit || true
shutdown -pD now
poweroff
