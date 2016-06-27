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

MODULE_ALIAS("pcmcia:m*c*f04fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0000c0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0007c0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m000Ac0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m001Cc0001f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0032c0704f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0032c2904f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0045c0401f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m004Fc0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0097c1620f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0098c0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m00A4c002Df*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m00CEc0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m0319c0000f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m2080c0001f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m4E01c0100f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m4E01c0200f*fn*pfn*pa*pb*pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa8C36137CpbD0693AB8pc2768A9F0pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa1B9179CApbEDE88951pc0D902F74pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa281F1C5Dpb1907960CpcF7FDE8B9pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa78F308DCpb66536591pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa78F308DCpb0C694728pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa46D7DB81pb66536591pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa7D93B852pb66536591pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paFF8C8A45pbFE8020C4pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa17692A66pbEF1DCBDEpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa6F58C983pb63C13AAFpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa0A5C52FDpb66536591pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa0A5C52FDpb0C694728pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa5714CBF7pb48E0AB8Epc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paF4F43949pb9EB86AAEpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paF4F43949pbA6D76178pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa3D5B9EF5pbCA6AB420pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paB569A6E5pbA6D76178pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paB569A6E5pbF2508753pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa2E6D1829pb55D5BFFBpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa2E6D1829pb531E7D10pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa2E6D1829pbACBE682Epc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa547E66DCpb8671043Bpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa547E66DCpb5C5AB149pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa547E66DCpbB3662674pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paE37BE2B5pb8671043Bpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa7ED2AD87pb7E9E78EEpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa7ED2AD87pb7A13045Cpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa*pbEBE0BD79pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa281F1C5Dpb66536591pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa281F1C5Dpb0C694728pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa4A3F0BA0pb322560E1pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa87C1B330pbE1F30883pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa43D74CB4pb6A22777Dpc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa30896C92pb703CC5F6pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paB4585A1Apb3489E003pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paD0909443pb*pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa709B1BF1pbF68B6F32pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa709B1BF1pb2A54D4B1pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa709B1BF1pb969AA4F2pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa709B1BF1pbF54A91C8pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa709B1BF1pb7558F133pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa709B1BF1pbB2F89B47pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa244E5994pb3E232852pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paCC7CF69Cpb212BB918pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paE4A13209pb*pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paBF2DF18Dpb8CB57A0Epc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn01pfn*pa7A954BD9pb74BE00C6pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*pa*pb5A362506pc*pd*");

MODULE_INFO(srcversion, "1F1A14E2F082CBB550B201E");
