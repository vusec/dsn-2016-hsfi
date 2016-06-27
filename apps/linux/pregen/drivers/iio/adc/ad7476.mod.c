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
"depends=industrialio,industrialio-triggered-buffer";

MODULE_ALIAS("spi:ad7091r");
MODULE_ALIAS("spi:ad7273");
MODULE_ALIAS("spi:ad7274");
MODULE_ALIAS("spi:ad7276");
MODULE_ALIAS("spi:ad7277");
MODULE_ALIAS("spi:ad7278");
MODULE_ALIAS("spi:ad7466");
MODULE_ALIAS("spi:ad7467");
MODULE_ALIAS("spi:ad7468");
MODULE_ALIAS("spi:ad7475");
MODULE_ALIAS("spi:ad7476");
MODULE_ALIAS("spi:ad7476a");
MODULE_ALIAS("spi:ad7477");
MODULE_ALIAS("spi:ad7477a");
MODULE_ALIAS("spi:ad7478");
MODULE_ALIAS("spi:ad7478a");
MODULE_ALIAS("spi:ad7495");
MODULE_ALIAS("spi:ad7910");
MODULE_ALIAS("spi:ad7920");
MODULE_ALIAS("spi:ad7940");
