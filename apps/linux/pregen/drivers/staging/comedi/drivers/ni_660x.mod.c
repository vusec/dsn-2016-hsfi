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

MODULE_INFO(staging, "Y");

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=comedi,ni_tio,mite,ni_tiocmd";

MODULE_ALIAS("pci:v00001093d00001310sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001360sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002C60sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002CC0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001E40sv*sd*bc*sc*i*");
