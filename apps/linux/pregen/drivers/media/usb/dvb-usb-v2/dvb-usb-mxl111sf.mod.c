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
"depends=dvb_usb_v2,tveeprom";

MODULE_ALIAS("usb:v2040pC600d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC601d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC602d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC603d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC604d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC609d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC60Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC60Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC60Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC653d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC65Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pB700d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pB701d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pB702d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pB703d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pB704d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pB753d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pB763d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pB764d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pD853d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pD854d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pD863d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pD864d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pD8D3d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pD8D4d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pD8E3d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pD8E4d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pD8FFd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC612d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC613d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC61Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pC61Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pB757d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2040pB767d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "A1DCAD1069399F0DF9F7965");
