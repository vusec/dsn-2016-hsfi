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
"depends=fb_ddc,vgastate";

MODULE_ALIAS("pci:v000012D2d00000018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000020sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000028sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000029sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000002Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000002Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000000A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000100sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000101sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000103sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000110sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000112sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000113sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000150sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000151sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000152sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000153sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000170sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000171sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000001F0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000172sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000174sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000175sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000176sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000178sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000179sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000017Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000017Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000017Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000001A0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000200sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000201sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000202sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000203sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000250sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000251sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000253sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000258sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000259sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000025Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000329sv*sd*bc*sc*i*");
