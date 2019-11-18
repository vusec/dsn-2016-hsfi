#!/bin/bash

set -e

: ${PATHROOT:="$PWD"}
if [ ! -f "$PATHROOT/autosetup.inc" ]; then
	echo "Please execute from the root of the repository or set PATHROOT" >&2
	exit 1
fi

LLVMBRANCH=RELEASE_33/final
LLVMVERSION=3.3
LLVMVERSIONCONF=3.3

source "$PATHROOT/autosetup.inc"

: ${URLVMIMAGENAME:=ubuntu-13.10.qcow2}
: ${URLVMIMAGE:="https://www.vusec.net/download/?t=dsn-2016-hsfi/$URLVMIMAGENAME.bz2"}
: ${PATHVMIMG:="$PATHVMS/$URLVMIMAGENAME"}

# download VM image
echo "Downloading VM image"
run mkdir -p "$PATHVMS"
[ -f "$PATHVMIMG.bz2" ] || run wget -O "$PATHVMIMG.bz2" "$URLVMIMAGE"
[ -f "$PATHVMIMG" ] || run bunzip2 -k "$PATHVMIMG.bz2"

# store settings
(
echo "export PATH=\"$PATHLLVM/bin/bin:$PATHAUTOPREFIX/bin:\$PATH\""
echo "PATHTOOLS=\"$PATHAUTOPREFIX\""
echo "PATHQEMU=\"$PATHAUTOPREFIX/bin/qemu-system-x86_64\""
echo "PATHVMIMG=\"$PATHVMIMG\""
) > "$PATHROOT/apps/linux/autosetup-paths.inc"

# build app
echo "Building linux"
cd "$PATHROOT/apps/linux"
export DISABLELTO
export JOBS
export PATHBINUTILS="$PATHAUTOPREFIX"
scripts/setup_unconditionalize.sh "$PATHROOT"
