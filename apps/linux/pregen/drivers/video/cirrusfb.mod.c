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

MODULE_ALIAS("pci:v00001013d000000ACsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000A8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000A4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d00001202sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d00000038sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000BCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000B8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000D0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000D4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001013d000000D6sv*sd*bc*sc*i*");
