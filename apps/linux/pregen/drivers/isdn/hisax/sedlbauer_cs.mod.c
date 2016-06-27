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

MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa81FB79F5pbF3612E1Dpc6B95C78Apd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa81FB79F5pbE4E9BC12pc397B7E90pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa81FB79F5pbE4E9BC12pc2E5C7FCEpd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa81FB79F5pbE4E9BC12pc8DB143FEpd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa81FB79F5pbE4E9BC12pcB391AB4Cpd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paD79E0B84pb21D083AEpc*pd*");
