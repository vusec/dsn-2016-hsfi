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
"depends=libiscsi,scsi_transport_iscsi,iscsi_boot_sysfs";

MODULE_ALIAS("pci:v00001077d00004010sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001077d00004022sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001077d00004032sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001077d00008022sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001077d00008032sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "034F0E29699C0DF5D5B7F14");
