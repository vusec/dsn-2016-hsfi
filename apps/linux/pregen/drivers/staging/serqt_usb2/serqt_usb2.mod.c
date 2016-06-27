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

MODULE_INFO(staging, "Y");

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=usbserial";

MODULE_ALIAS("usb:v061DpC030d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC040d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC050d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC060d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC070d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC080d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC081d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC0A0d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC0A1d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC090d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC091d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC092d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC093d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC0B0d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC0B1d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC0B2d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v061DpC0B3d*dc*dsc*dp*ic*isc*ip*in*");
