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
"depends=qlogicfas408,pcmcia";

MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa88395FA7pb33B7A5E6pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paD361772Fpb299D1751pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa20841B68pbAB3C3B6Dpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa6534382ApbD67EEE79pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa18DF0BA0pb24662E8Apc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa82375A27pbF68E5BF7pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa82375A27pb68EACE54pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa3FAEE676pb194250ECpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paD77B2930pbA85B2735pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paD77B2930pb70F8B5F8pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa3FAEE676pb81896B61pcF99F065Fpd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa85C10E17pb1A2640C1pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paB4585A1ApbA6F06EBEpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paB4585A1Apb0A88DEA0pc*pd*");
