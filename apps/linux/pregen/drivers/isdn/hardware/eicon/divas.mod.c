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
"depends=divadidd";

MODULE_ALIAS("pci:v00001133d0000E010sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001133d0000E012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001133d0000E013sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001133d0000E014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001133d0000E015sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001133d0000E016sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001133d0000E017sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001133d0000E018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001133d0000E019sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001133d0000E01Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001133d0000E01Bsv*sd*bc*sc*i*");
