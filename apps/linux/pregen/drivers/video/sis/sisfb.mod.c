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

MODULE_ALIAS("pci:v00001039d00000300sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00005300sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00006300sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00000310sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00000315sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00000325sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00005315sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00006325sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00000330sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001039d00006330sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000018CAd00000020sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000018CAd00000040sv*sd*bc*sc*i*");
