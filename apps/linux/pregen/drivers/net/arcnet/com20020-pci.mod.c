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
"depends=com20020,arcnet";

MODULE_ALIAS("pci:v00001571d0000A001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A002sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A003sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A004sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A005sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A006sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A007sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A008sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A009sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A00Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A00Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A00Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A00Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A00Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A201sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A202sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A203sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A204sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A205sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001571d0000A206sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00009030sv000010B5sd00002978bc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00009050sv000010B5sd00002273bc*sc*i*");
MODULE_ALIAS("pci:v000014BAd00006000sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00002200sv*sd*bc*sc*i*");
