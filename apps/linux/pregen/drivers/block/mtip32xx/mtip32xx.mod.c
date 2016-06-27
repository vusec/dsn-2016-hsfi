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

MODULE_ALIAS("pci:v00001344d00005150sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001344d00005151sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001344d00005152sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001344d00005153sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001344d00005160sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001344d00005161sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001344d00005163sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "23EB22B9EAFAF0C6C235686");
