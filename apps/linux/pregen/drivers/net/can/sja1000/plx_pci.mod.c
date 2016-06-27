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
"depends=sja1000";

MODULE_ALIAS("pci:v0000144Ad00007841sv*sd*bc02sc80i00*");
MODULE_ALIAS("pci:v0000144Ad00007841sv*sd*bc07sc80i00*");
MODULE_ALIAS("pci:v000010B5d00009050sv000012FEsd00000004bc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00009030sv000012FEsd0000010Bbc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00009030sv000012FEsd00000501bc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00009056sv000012FEsd00000009bc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00009056sv000012FEsd0000000Ebc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00009056sv000012FEsd00000200bc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00009050sv*sd00002540bc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00002715sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001498d0000032Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00009030sv000012C4sd00000900bc*sc*i*");
