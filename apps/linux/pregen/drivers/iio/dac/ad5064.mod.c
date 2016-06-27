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
"depends=industrialio";

MODULE_ALIAS("i2c:ad5629-1");
MODULE_ALIAS("i2c:ad5629-2");
MODULE_ALIAS("i2c:ad5629-3");
MODULE_ALIAS("i2c:ad5669-1");
MODULE_ALIAS("i2c:ad5669-2");
MODULE_ALIAS("i2c:ad5669-3");
MODULE_ALIAS("spi:ad5024");
MODULE_ALIAS("spi:ad5025");
MODULE_ALIAS("spi:ad5044");
MODULE_ALIAS("spi:ad5045");
MODULE_ALIAS("spi:ad5064");
MODULE_ALIAS("spi:ad5064-1");
MODULE_ALIAS("spi:ad5065");
MODULE_ALIAS("spi:ad5628-1");
MODULE_ALIAS("spi:ad5628-2");
MODULE_ALIAS("spi:ad5648-1");
MODULE_ALIAS("spi:ad5648-2");
MODULE_ALIAS("spi:ad5666-1");
MODULE_ALIAS("spi:ad5666-2");
MODULE_ALIAS("spi:ad5668-1");
MODULE_ALIAS("spi:ad5668-2");
MODULE_ALIAS("spi:ad5668-3");
