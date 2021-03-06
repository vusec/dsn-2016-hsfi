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
"depends=libahci";

MODULE_ALIAS("of:N*T*Csnps,spear-ahci*");
MODULE_ALIAS("of:N*T*Csnps,exynos5440-ahci*");
MODULE_ALIAS("platform:ahci");
MODULE_ALIAS("platform:imx53-ahci");
MODULE_ALIAS("platform:strict-ahci");
