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

MODULE_ALIAS("pnp:dPNP0C31*");
MODULE_ALIAS("acpi*:PNP0C31:*");
MODULE_ALIAS("pnp:dATM1200*");
MODULE_ALIAS("acpi*:ATM1200:*");
MODULE_ALIAS("pnp:dIFX0102*");
MODULE_ALIAS("acpi*:IFX0102:*");
MODULE_ALIAS("pnp:dBCM0101*");
MODULE_ALIAS("acpi*:BCM0101:*");
MODULE_ALIAS("pnp:dBCM0102*");
MODULE_ALIAS("acpi*:BCM0102:*");
MODULE_ALIAS("pnp:dNSC1200*");
MODULE_ALIAS("acpi*:NSC1200:*");
MODULE_ALIAS("pnp:dICO0102*");
MODULE_ALIAS("acpi*:ICO0102:*");
MODULE_ALIAS("pnp:d*");
MODULE_ALIAS("acpi*::*");

MODULE_INFO(srcversion, "6F317DAD55F9E80DB06D0E9");
