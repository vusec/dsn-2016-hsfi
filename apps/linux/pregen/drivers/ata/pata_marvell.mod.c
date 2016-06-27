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

MODULE_ALIAS("pci:v000011ABd00006101sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00006121sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00006123sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00006145sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001B4Bd000091A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001B4Bd000091A4sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "A865313D13C66B18EEE8CCC");
