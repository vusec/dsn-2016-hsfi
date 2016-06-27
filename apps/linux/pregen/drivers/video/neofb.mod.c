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
"depends=vgastate";

MODULE_ALIAS("pci:v000010C8d00000001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000002sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000003sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000083sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000004sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000005sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000025sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000006sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010C8d00000016sv*sd*bc*sc*i*");
