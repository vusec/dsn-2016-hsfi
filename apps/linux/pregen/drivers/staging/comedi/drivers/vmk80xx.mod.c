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
"depends=comedi";

MODULE_ALIAS("usb:v10CFp5500d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp5501d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp5502d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp5503d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8061d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8062d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8063d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8064d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8065d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8066d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8067d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v10CFp8068d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "8610606772EE57AC1BBEB8A");
