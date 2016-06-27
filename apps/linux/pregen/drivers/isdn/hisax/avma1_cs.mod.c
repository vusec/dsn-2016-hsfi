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
"depends=pcmcia,hisax";

MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa95D42008pbADC9D4BBpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa8D9761C8pb01C5AA7Bpc*pd*");
