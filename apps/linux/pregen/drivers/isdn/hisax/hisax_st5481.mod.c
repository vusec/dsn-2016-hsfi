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
"depends=hisax,isdnhdlc";

MODULE_ALIAS("usb:v0483p4810d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p4811d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p4812d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p4813d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p4814d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p4815d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p4816d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p4817d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p4818d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p4819d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p481Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p481Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p481Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p481Dd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p481Ed*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0483p481Fd*dc*dsc*dp*ic*isc*ip*in*");
