#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("pci:v00001393d00001680sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001040sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001320sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001141sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001140sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001020sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001041sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001681sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001321sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001340sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001042sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00000001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001180sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001021sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001022sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001181sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001682sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001043sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001080sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001142sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001341sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001380sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001044sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001143sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001023sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001393d00001120sv*sd*bc*sc*i*");
