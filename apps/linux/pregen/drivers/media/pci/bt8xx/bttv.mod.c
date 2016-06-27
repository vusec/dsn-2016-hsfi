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
"depends=rc-core,tveeprom,videobuf-dma-sg,videobuf-core,btcx-risc,v4l2-common,videodev";

MODULE_ALIAS("pci:v0000109Ed00000350sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000109Ed00000351sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000109Ed0000036Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000109Ed0000036Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000109Ed0000036Csv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "88DF5D1A0DD9317A2BDD516");
