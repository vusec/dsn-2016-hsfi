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

MODULE_ALIAS("pci:v000013FEd00001710sv000010B5sd00009050bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001710sv000013FEsd00000000bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001710sv000013FEsd0000B100bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001710sv000013FEsd0000B200bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001710sv000013FEsd0000C100bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001710sv000013FEsd0000C200bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001710sv00001000sd0000D100bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001710sv000013FEsd00000002bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001710sv000013FEsd0000B102bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001710sv000013FEsd0000B202bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001710sv000013FEsd0000C102bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001710sv000013FEsd0000C202bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001710sv00001000sd0000D102bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001711sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001713sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001720sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013FEd00001731sv*sd*bc*sc*i*");
