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
"depends=scsi_transport_iscsi,libiscsi,iscsi_boot_sysfs";

MODULE_ALIAS("pci:v000019A2d00000212sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000019A2d00000222sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000019A2d00000702sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000019A2d00000703sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000019A2d00000712sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010DFd00000722sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "B9963B6F418CD0686BB90E0");
