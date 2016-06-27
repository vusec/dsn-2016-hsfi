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
"depends=budget-core,saa7146,dvb-core";

MODULE_ALIAS("pci:v00001131d00007146sv000013C2sd00001003bc*sc*i*");
MODULE_ALIAS("pci:v00001131d00007146sv000013C2sd00001004bc*sc*i*");
MODULE_ALIAS("pci:v00001131d00007146sv000013C2sd00001005bc*sc*i*");
MODULE_ALIAS("pci:v00001131d00007146sv000013C2sd00001013bc*sc*i*");
MODULE_ALIAS("pci:v00001131d00007146sv000013C2sd00001016bc*sc*i*");
MODULE_ALIAS("pci:v00001131d00007146sv000013C2sd00001018bc*sc*i*");
MODULE_ALIAS("pci:v00001131d00007146sv000013C2sd0000101Cbc*sc*i*");
MODULE_ALIAS("pci:v00001131d00007146sv00001131sd00004F60bc*sc*i*");
MODULE_ALIAS("pci:v00001131d00007146sv00001131sd00004F61bc*sc*i*");
MODULE_ALIAS("pci:v00001131d00007146sv00001131sd00005F60bc*sc*i*");
MODULE_ALIAS("pci:v00001131d00007146sv00001131sd00005F61bc*sc*i*");
MODULE_ALIAS("pci:v00001131d00007146sv000014C4sd00001020bc*sc*i*");
MODULE_ALIAS("pci:v00001131d00007146sv00001131sd00004F52bc*sc*i*");
