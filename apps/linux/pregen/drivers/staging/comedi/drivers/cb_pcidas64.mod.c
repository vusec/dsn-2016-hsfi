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
"depends=comedi,8255,comedi_fc";

MODULE_ALIAS("pci:v00001307d0000001Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d0000001Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000035sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000036sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000037sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000052sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d0000005Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d0000005Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d0000005Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000060sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000061sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000062sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000063sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000064sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000065sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000066sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000067sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000068sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d0000006Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000078sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001307d00000079sv*sd*bc*sc*i*");
