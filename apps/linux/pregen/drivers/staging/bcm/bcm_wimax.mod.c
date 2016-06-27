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
"depends=";

MODULE_ALIAS("usb:v198Fp0300d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v198Fp0210d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v198Fp0220d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v198Fp015Ed*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v19D2p0132d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0489pE017d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v19D2p0007d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v19D2p0172d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v19D2p0173d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "EF7383DD3002DD0687C1F83");
