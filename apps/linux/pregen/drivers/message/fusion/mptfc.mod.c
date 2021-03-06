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
"depends=mptscsih,mptbase,scsi_transport_fc";

MODULE_ALIAS("pci:v00001000d00000621sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000624sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000622sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000628sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000626sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000642sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000640sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000646sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001657d00000646sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "F4A7A3DEF554D8E0CFFDAF7");
