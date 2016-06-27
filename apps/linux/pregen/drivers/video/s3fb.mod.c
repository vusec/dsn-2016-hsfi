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
"depends=svgalib,fb_ddc,vgastate";

MODULE_ALIAS("pci:v00005333d00008810sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008811sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008812sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008814sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008901sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008902sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00005631sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d0000883Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A01sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A10sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A11sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A12sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008A13sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008904sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00005333d00008C01sv*sd*bc*sc*i*");
