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

MODULE_ALIAS("acpi*:INT33C4:*");
MODULE_ALIAS("acpi*:INT33C5:*");
MODULE_ALIAS("acpi*:80860F0A:*");
MODULE_ALIAS("of:N*T*Csnps,dw-apb-uart*");
MODULE_ALIAS("of:N*T*Ccavium,octeon-3860-uart*");
