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
"depends=dvb_usb_v2,rc-core";

MODULE_ALIAS("usb:v1B80pE409d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v048Dp9135d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1B80pE411d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v048Dp9005d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v048Dp9006d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07CAp1835d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07CAp2835d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07CAp3835d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07CAp4835d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1B80pE410d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "5871E4012D235CEF34BBF89");
