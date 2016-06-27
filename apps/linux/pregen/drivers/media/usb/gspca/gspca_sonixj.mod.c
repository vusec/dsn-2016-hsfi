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
"depends=gspca_main,videodev";

MODULE_ALIAS("usb:v0458p7025d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0458p702Ed*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v045Ep00F5d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v045Ep00F7d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0471p0327d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0471p0328d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0471p0330d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v06F8p3004d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v06F8p3008d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p6040d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p607Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p60C0d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p60CEd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p60ECd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p60FBd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p60FCd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p60FEd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p6100d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p6102d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p610Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p610Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p610Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p610Ed*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p6128d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p612Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p612Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p612Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p612Ed*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p6130d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p6138d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p613Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p613Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p613Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p613Ed*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p6142d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p6143d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p6148d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0C45p614Ad*dc*dsc*dp*ic*isc*ip*in*");
