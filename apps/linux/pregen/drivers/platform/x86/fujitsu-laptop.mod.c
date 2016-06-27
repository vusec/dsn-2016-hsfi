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

MODULE_ALIAS("pnp:dFUJ02bf*");
MODULE_ALIAS("acpi*:FUJ02BF:*");
MODULE_ALIAS("pnp:dFUJ02B1*");
MODULE_ALIAS("acpi*:FUJ02B1:*");
MODULE_ALIAS("pnp:dFUJ02E3*");
MODULE_ALIAS("acpi*:FUJ02E3:*");

MODULE_INFO(srcversion, "F10090B5797DC5D541851D0");
