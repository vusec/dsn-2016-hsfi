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
"depends=snd-rawmidi,snd,snd-mpu401-uart,snd-wss-lib,snd-hwdep,snd-opl3-lib";

MODULE_ALIAS("pnp:dCSC0000*");
MODULE_ALIAS("acpi*:CSC0000:*");
MODULE_ALIAS("pnp:dCSC0010*");
MODULE_ALIAS("acpi*:CSC0010:*");
MODULE_ALIAS("pnp:dPnPb006*");
MODULE_ALIAS("acpi*:PNPB006:*");
MODULE_ALIAS("pnp:dCSC0004*");
MODULE_ALIAS("acpi*:CSC0004:*");
