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

MODULE_ALIAS("pci:v00001014d0000002Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001014d000001BDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00000250sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "4E58889ABF3B68AE3E896C4");
