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
"depends=industrialio,ad_sigma_delta";

MODULE_ALIAS("spi:ad7785");
MODULE_ALIAS("spi:ad7792");
MODULE_ALIAS("spi:ad7793");
MODULE_ALIAS("spi:ad7794");
MODULE_ALIAS("spi:ad7795");
MODULE_ALIAS("spi:ad7796");
MODULE_ALIAS("spi:ad7797");
MODULE_ALIAS("spi:ad7798");
MODULE_ALIAS("spi:ad7799");
