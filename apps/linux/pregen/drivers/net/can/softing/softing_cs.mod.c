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

MODULE_ALIAS("pcmcia:m0168c0001f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0168c0002f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0168c0004f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0168c0005f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0168c0081f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0168c0084f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0168c0085f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0168c0102f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0168c0105f*fn*pfn*pa*pb*pc*pd*");
