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
"depends=ssb,mii";

MODULE_ALIAS("ssb:v4243id0806rev*");
MODULE_ALIAS("pci:v000014E4d00004401sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d00004402sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000014E4d0000170Csv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "A3C1877A4B92BEE71FD75B5");
