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

MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa547E66DCpb0D63A3FDpc51DE003Apd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa534C02BCpb52008408pc51DE003Apd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa534C02BCpbCB09D5B2pc51DE003Apd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa534C02BCpbBC0EE524pc51DE003Apd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa534C02BCpb226A7087pc51DE003Apd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paC7BA805FpbFDC7C97Dpc6973710Epd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa28191418pbB70F4B09pc51DE003Apd*");
