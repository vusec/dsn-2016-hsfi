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
"depends=videodev,videocodec,v4l2-common";

MODULE_ALIAS("pci:v000011DEd00006057sv00001031sd00007EFEbc*sc*i*");
MODULE_ALIAS("pci:v000011DEd00006057sv00001031sd0000D801bc*sc*i*");
MODULE_ALIAS("pci:v000011DEd00006057sv000012F8sd00008A02bc*sc*i*");
MODULE_ALIAS("pci:v000011DEd00006057sv000013CAsd00004231bc*sc*i*");
MODULE_ALIAS("pci:v000011DEd00006057sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "5BA63E0BB96D58B597A7B75");
