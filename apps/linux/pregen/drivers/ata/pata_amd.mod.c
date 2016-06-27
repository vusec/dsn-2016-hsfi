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

MODULE_ALIAS("pci:v00001022d00007401sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001022d00007409sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001022d00007411sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001022d00007441sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001022d00007469sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000001BCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000065sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000085sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000000D5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000000E5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000053sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000035sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000265sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000036Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd000003ECsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000448sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000560sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd0000056Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DEd00000759sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001022d0000209Asv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "C213708D46BC0E4EEFB4330");
