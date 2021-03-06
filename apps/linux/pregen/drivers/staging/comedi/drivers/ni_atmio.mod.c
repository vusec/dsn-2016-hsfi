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

MODULE_INFO(staging, "Y");

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=comedi,ni_tio,8255,comedi_fc";

MODULE_ALIAS("pnp:dNIC1900*");
MODULE_ALIAS("acpi*:NIC1900:*");
MODULE_ALIAS("pnp:dNIC2400*");
MODULE_ALIAS("acpi*:NIC2400:*");
MODULE_ALIAS("pnp:dNIC2500*");
MODULE_ALIAS("acpi*:NIC2500:*");
MODULE_ALIAS("pnp:dNIC2600*");
MODULE_ALIAS("acpi*:NIC2600:*");
MODULE_ALIAS("pnp:dNIC2700*");
MODULE_ALIAS("acpi*:NIC2700:*");
