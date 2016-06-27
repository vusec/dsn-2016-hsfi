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
"depends=rc-core";

MODULE_ALIAS("pnp:dENE0100*");
MODULE_ALIAS("acpi*:ENE0100:*");
MODULE_ALIAS("pnp:dENE0200*");
MODULE_ALIAS("acpi*:ENE0200:*");
MODULE_ALIAS("pnp:dENE0201*");
MODULE_ALIAS("acpi*:ENE0201:*");
MODULE_ALIAS("pnp:dENE0202*");
MODULE_ALIAS("acpi*:ENE0202:*");
