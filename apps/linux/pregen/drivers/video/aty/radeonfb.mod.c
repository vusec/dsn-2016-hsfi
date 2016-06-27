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
"depends=fb_ddc";

MODULE_ALIAS("pci:v00001002d00005955sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005975sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C59sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C5Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005159sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000515Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000515Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004336sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004136sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004337sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004137sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004437sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004237sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004242sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004243sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005148sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000514Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000514Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C57sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C58sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005157sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005158sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C64sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C65sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C66sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004C67sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004966sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004967sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005A62sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005835sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007835sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005834sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00007834sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005C61sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005C63sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005960sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005961sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005962sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005964sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004144sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004145sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004146sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004147sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E44sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E45sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E46sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E47sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E50sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E51sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E52sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E53sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E54sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E56sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004150sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004151sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004152sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004153sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004154sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004156sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004148sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004149sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000414Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000414Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E48sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E49sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E4Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004E4Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00003E50sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00003E54sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00003150sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00003154sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005B60sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005B62sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005B63sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005B64sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005B65sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005460sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005464sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A48sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A49sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A4Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A4Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A4Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A4Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A4Esv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00004A50sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005548sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005549sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000554Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d0000554Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005551sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005552sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005554sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005D57sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005144sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005145sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005146sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001002d00005147sv*sd*bc*sc*i*");
