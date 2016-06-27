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
"depends=comedi";

MODULE_ALIAS("pci:v00001762d00003111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001762d00001111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001762d00003112sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001762d00003113sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001762d00003114sv*sd*bc*sc*i*");
