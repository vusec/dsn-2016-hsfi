#Generated makefile PWD
include $(MYPWD)mypwd.mk
#Here we have variables that should be used across the llvmlinux pre-build system
LLVM_APPS_VARS=common.inc

CLANGCC = $(CLANG_BIN)/bin/clang
LLVMLD = ld.gold
MHOSTCC = gcc -m32
#Kernel related variables
KERNEL_GIT = https://github.com/andikleen/linux-misc.git
KERNEL_SRC = $(MYPWD)/src
KERNEL_BRANCH = master
KERNEL_TAG = lto-3.11
KERNEL_CFG = new_config
KERNEL_PATCHES = $(MYPWD)/patches/linux
KERNEL_PREGEN= $(MYPWD)/pregen
KERNEL_VAR = -j1 
KERNEL_VAR += CONFIG_DEBUG_INFO=1 CONFIG_DEBUG_SECTION_MISMATCH=y CONFIG_NO_ERROR_ON_MISMATCH=y 

EMPTY_ELF = $(MYPWD)/empty_obj

#Toolchain related variables
TOOL_TOP = $(MYPWD)/toolchain
LLVM_GIT = http://llvm.org/git/llvm.git
LLVM_SRC = $(TOOL_TOP)/src
LLVM_BUILD = $(TOOL_TOP)/build
LLVM_BIN = $(TOOL_TOP)/install
LLVM_COMMIT = release_33
LLVM_PATCHES = $(MYPWD)/patches/llvm

CLANG_GIT = http://llvm.org/git/clang.git
CLANG_SRC = $(TOOL_TOP)/src/tools/clang
CLANG_BUILD = $(TOOL_TOP)/build
CLANG_BIN = $(TOOL_TOP)/install
CLANG_COMMIT = release_33
CLANG_PATCHES = $(MYPWD)/patches/clang

_export_paths:
	@echo KERNEL_SRC=$(KERNEL_SRC) > $(LLVM_APPS_VARS)
	@echo TOOL_TOP=$(TOOL_TOP) >> $(LLVM_APPS_VARS)
	@echo CLANG_BIN=$(CLANG_BIN) >> $(LLVM_APPS_VARS)
	@echo CLANG_BUILD=$(CLANG_BUILD) >> $(LLVM_APPS_VARS)
	@echo LLVM_BIN=$(LLVM_BIN) >> $(LLVM_APPS_VARS)
	@echo LLVM_BUILD=$(LLVM_BUILD) >> $(LLVM_APPS_VARS)
