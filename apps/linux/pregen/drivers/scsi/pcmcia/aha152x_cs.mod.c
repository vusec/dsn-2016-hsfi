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
"depends=pcmcia";

MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paCDF7E4CCpb35F26476pcA8851D6Epd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paAD89C6E8pb35F26476pcA8851D6Epd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa24BA9738pb3A3C3D20pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa085A850Bpb80A6535Cpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paAD89C6E8pb5F9A615Bpc*pd*");
