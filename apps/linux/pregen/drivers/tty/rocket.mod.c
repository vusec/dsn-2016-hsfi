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

MODULE_ALIAS("pci:v000011FEd00000004sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000005sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000805sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000002sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000802sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000006sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000007sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000008sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000009sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000003sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000803sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000903sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd00000801sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd0000000Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd0000000Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd0000000Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd0000000Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd0000000Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd0000000Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd0000080Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011FEd0000080Dsv*sd*bc*sc*i*");
