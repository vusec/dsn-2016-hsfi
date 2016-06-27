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

MODULE_ALIAS("usb:v06F8p3009d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v06F8p301Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v093Ap2620d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v093Ap2621d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v093Ap2622d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v093Ap2624d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v093Ap2625d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v093Ap2626d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v093Ap2627d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v093Ap2628d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v093Ap2629d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v093Ap262Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v093Ap262Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v145Fp013Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1AE7p2001d*dc*dsc*dp*ic*isc*ip*in*");
