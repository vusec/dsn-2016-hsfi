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

MODULE_ALIAS("pnp:dADP1502*");
MODULE_ALIAS("pnp:dADP1505*");
MODULE_ALIAS("pnp:dADP1510*");
MODULE_ALIAS("pnp:dADP1515*");
MODULE_ALIAS("pnp:dADP1520*");
MODULE_ALIAS("pnp:dADP2015*");
MODULE_ALIAS("pnp:dADP1522*");
MODULE_ALIAS("pnp:dADP2215*");
MODULE_ALIAS("pnp:dADP1530*");
MODULE_ALIAS("pnp:dADP3015*");
MODULE_ALIAS("pnp:dADP1532*");
MODULE_ALIAS("pnp:dADP3215*");
MODULE_ALIAS("pnp:dADP6360*");
