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

MODULE_ALIAS("dmi*:svn*VIA*:pn*K8N800*:pvr*VT8204B*:");
MODULE_ALIAS("dmi*:svn*CLEVOCo.*:pn*M5x0N*:");
MODULE_ALIAS("dmi*:pvr*VT6198*:rvn*CLEVOCo.*:rn*M5X0V*:");
MODULE_ALIAS("dmi*:pvr*0106*:rvn*Clevo*:rn*D400P*:rvr*Rev.A*:");
MODULE_ALIAS("dmi*:pvr*Rev.A1*:rvn*Clevo,Co.*:rn*D400V/D470V*:rvr*SS78B*:");
