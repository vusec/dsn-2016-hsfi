#Makefile for llvmlinux

all: kernel-build
include utils.mk
include vars.mk


###############################################
# Toolchain build rules
###############################################

state/fetch-toolchain:
	$(call gitclone,$(LLVM_GIT) -b $(KERNEL_BRANCH),$(LLVM_SRC))
	$(call echo,- Checking out llvm commit: \<$(LLVM_COMMIT)\>)
	$(call gitcheckout,$(LLVM_SRC),$(LLVM_COMMIT))
	$(call gitclone,$(CLANG_GIT) -b $(KERNEL_BRANCH),$(CLANG_SRC))
	$(call echo,- Checking out llvm commit: \<$(CLANG_COMMIT)\>)
	$(call gitcheckout,$(CLANG_SRC),$(CLANG_COMMIT))
	$(call state,$@,patch-llvm)
	$(call state,$@,patch-clang)

patch-llvm: state/patch-llvm
state/patch-llvm: state/fetch-toolchain
	@$(call patches_dir,${LLVM_PATCHES},${LLVM_SRC}/patches)
	@$(call patch,$(LLVM_SRC))
	$(call state,$@,config-llvm)

patch-clang: state/patch-clang
state/patch-clang: state/fetch-toolchain
	@$(call patches_dir,${CLANG_PATCHES},${CLANG_SRC}/patches)
	@$(call patch,$(CLANG_SRC))
	$(call state,$@,config-llvm)

config-llvm: state/config-llvm
state/config-llvm: state/patch-llvm state/patch-clang
	@$(call llvmconfig,LLVM,${LLVM_BUILD},${LLVM_BIN},,${LLVM_SRC})
	$(call state,$@,build-llvm)

build-llvm: state/build-llvm
state/build-llvm: state/config-llvm
	$(MAKE) -C $(LLVM_BUILD) install
	$(call state,$@)

###############################################
# Kernel build rules
###############################################
state/kernel-fetch:
	$(call gitclone,$(KERNEL_GIT) -b $(KERNEL_BRANCH),$(KERNEL_SRC))
	$(call echo,- Checking out tagged kernel: \<$(KERNEL_TAG)\>)
	$(call gitcheckout,$(KERNEL_SRC),$(KERNEL_TAG))
	@ln -s $(MYPWD)/edfi_server $(KERNEL_SRC)/edfi
	@cp $(MYPWD)/common.inc $(KERNEL_SRC)/scripts/llvm_apps.inc
	$(call state,$@)

kernel-config: state/kernel-config
state/kernel-config: state/kernel-fetch
	cp $(KERNEL_CFG) $(KERNEL_SRC)/.config
	$(call state,$@,kernel-patch)

kernel-patch: state/kernel-patch
state/kernel-patch: kernel-config
	@$(call patches_dir,${KERNEL_PATCHES},${KERNEL_SRC}/patches)
	@$(call patch,$(KERNEL_SRC))
#	@$(call gitpoint, $(KERNEL_SRC))
	$(call state,$@,kernel-prebuild)
	
kernel-prebuild: state/kernel-prebuild
state/kernel-prebuild: kernel-patch
	./copy_pregen $(KERNEL_PREGEN) $(KERNEL_SRC)
	cp $(EMPTY_ELF) $(KERNEL_SRC)
	$(call state,$@,kernel-build)
	
kernel-build: state/kernel-build
state/kernel-build: kernel-prebuild build-llvm
	$(MAKE) -C ${KERNEL_SRC} oldconfig
	$(MAKE) -C ${KERNEL_SRC} CC?="${CLANGCC}" LD?="${LLVMLD}" HOSTCC?="${MHOSTCC}" LLVM_VARS?="${CURDIR}"


###############################################
install: all
	touch build.done

clean:
	rm -rf state/kernel*
	rm -rf src
	rm -f build.done

mr-proper: clean
	rm -rf state
	rm -rf toolchain

