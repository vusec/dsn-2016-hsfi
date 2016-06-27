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
"depends=mantis_core";

MODULE_ALIAS("pci:v00001822d00004E35sv00001822sd00000016bc*sc*i*");
MODULE_ALIAS("pci:v00001822d00004E35sv00001822sd00000014bc*sc*i*");
MODULE_ALIAS("pci:v00001822d00004E35sv00001822sd00000031bc*sc*i*");
MODULE_ALIAS("pci:v00001822d00004E35sv00001AE4sd00000001bc*sc*i*");
MODULE_ALIAS("pci:v00001822d00004E35sv00001AE4sd00000003bc*sc*i*");
MODULE_ALIAS("pci:v00001822d00004E35sv0000153Bsd00001179bc*sc*i*");
MODULE_ALIAS("pci:v00001822d00004E35sv00001822sd00000008bc*sc*i*");
MODULE_ALIAS("pci:v00001822d00004E35sv00001822sd00000043bc*sc*i*");
MODULE_ALIAS("pci:v00001822d00004E35sv00001AE4sd00000002bc*sc*i*");
MODULE_ALIAS("pci:v00001822d00004E35sv0000153Bsd00001178bc*sc*i*");
MODULE_ALIAS("pci:v00001822d00004E35sv00001822sd00000024bc*sc*i*");
