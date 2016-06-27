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
"depends=libsas,scsi_transport_sas";

MODULE_ALIAS("pci:v00008086d00001D61sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D63sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D65sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D67sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D69sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D6Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D60sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D62sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D64sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D66sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D68sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001D6Asv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "0528EE062D0E0F547E474BA");
