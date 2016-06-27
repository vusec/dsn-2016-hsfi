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
"depends=snd,snd-ak4113,snd-ak4114,snd-ak4xxx-adda,snd-pt2258,snd-i2c,snd-ice17xx-ak4xxx,snd-ac97-codec,snd-pcm,snd-rawmidi";

MODULE_ALIAS("pci:v00001412d00001724sv*sd*bc*sc*i*");
