HSFI
====

Supported systems
-----------------

HSFI can be built on Linux and applied to programs that can be compiled
with LLVM using link-time optimizations (LTO). The repository includes
versions of LLVMLinux and MINIX3 prepared to be used with HSFI.

On the build machine, our system requires approximately 16GB of disk space
to build Linux and 35GB to build MINIX3. This includes dependencies fetched
by the automatic build script. The system also requires a functional
internet connection to be able to download required packages.
We recommend building HSFI on a machine with at least 8GB of RAM
but preferably more as link-time optimizations cause the linker
to use a considerable amount of memory.

Prerequisites
-------------

While our automatic setup script downloads and builds some of the most important
dependencies, our system does require some packages to be present on the machine
used to build it. We have tested the HSFI build on ubuntu-15.10-server-amd64
and found that it requires the following packages to be installed before
the automatic build script is invoked:

    sudo apt-get install bc bison curl flex install g++ gcc gcc-multilib \
                         gettext git libboost-dev libboost-system-dev    \
			 libboost-thread-dev make pkg-config python ssh  \
			 subversion texlive zlib1g-dev

It should be noted that our system cannot be compiled with 5.x versions of GCC
because these versions cannot properly compile LLVM plugins.
A 4.x version of GCC must be installed to be able to build HSFI.

Building HSFI
---------------

After ensuring that all prerequisites are installed, download the HSFI
source repository as follows:

    git clone https://github.com/vusec/hsfi.git

Next, invoke the automatic build script:

    cd hsfi
    ./autosetup-linux.sh

Or:

    cd hsfi
    ./autosetup-minix.sh

These scripts download, build and install the remaining dependencies locally
(in the autosetup.dir subdirectory), download and build the Linux or MINIX3
source tree and create (MINIX3) or download (Linux) a virtual machine image
to conduct experiments with.

We recommend building the operating systems in the separate copies of
our git repository as they require slightly different configurations and
cannot be used simultaneously from the same directory tree.

Running HSFI
------------

To perform fault injection experiments, use the
prun-scripts/edfi-unconditionalize.sh script from either the apps/linux or
apps/minix directory. These scripts perform the following steps:

* recompile the system with the specified injection model
* create a new virtual machine with the recompiled system
* the first run serves as a golden run with no faults injected
* on subsequent runs the script selects faults (using the results
  from the golden run to ensure they are actually triggered) and injects them
* finally, the script starts the virtual machine and executes the specified
  workload to test the system

There are many environment variables that can be used to configure the script.
These are the most important ones:

* BENCHMARK:      1 runs the MINIX test suite,
                  2 runs Unixbench
* INJECTFAULTS:   set to non-zero value to enable fault injection
                  (the default is to merely test performance
                  without injecting actual faults)
* INJECTIONMODEL: 0 does not inject faults,
                  1 injects faults using traditional EDFI
                  4 injects faults using HSFI
* INLINEPROFILING set to non-zero value to profile the system;
                  required on a golden run
* PRUNITER:       number of experiments to perform

Execution logs are stored in the results directory under
the root directory of the git repository. The serial-*.txt files contain
the output of the operating system which allows the impact of the fault to
be studied. The hypermemlog-*.txt files contains evens recorded by the
hypervisor through a hypercall inferface and allows events to be timed and
to be processed automatically.
