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

MODULE_ALIAS("pci:v00001103d00003220sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003320sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003410sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003510sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003511sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003520sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003521sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003522sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003530sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003540sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003560sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00004210sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00004211sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00004310sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00004311sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00004320sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00004321sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00004322sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00004400sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003120sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003122sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00003020sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00004520sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001103d00004522sv*sd*bc*sc*i*");
