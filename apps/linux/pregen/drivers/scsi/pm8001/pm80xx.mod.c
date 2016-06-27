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

MODULE_ALIAS("pci:v000011F8d00008001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000117Cd00000042sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011F8d00008008sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008008sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011F8d00008018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011F8d00008009sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008009sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011F8d00008019sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008019sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008081sv00009005sd00000400bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008081sv00009005sd00000800bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008088sv00009005sd00000008bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008088sv00009005sd00000800bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008089sv00009005sd00000008bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008089sv00009005sd00000800bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008088sv00009005sd00000016bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008088sv00009005sd00001600bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008089sv00009005sd00000016bc*sc*i*");
MODULE_ALIAS("pci:v00009005d00008089sv00009005sd00001600bc*sc*i*");

MODULE_INFO(srcversion, "CE85736B6874F776A7BBC6C");
