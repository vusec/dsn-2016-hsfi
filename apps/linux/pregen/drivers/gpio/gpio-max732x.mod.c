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

MODULE_ALIAS("i2c:max7319");
MODULE_ALIAS("i2c:max7320");
MODULE_ALIAS("i2c:max7321");
MODULE_ALIAS("i2c:max7322");
MODULE_ALIAS("i2c:max7323");
MODULE_ALIAS("i2c:max7324");
MODULE_ALIAS("i2c:max7325");
MODULE_ALIAS("i2c:max7326");
MODULE_ALIAS("i2c:max7327");
