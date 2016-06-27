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

MODULE_INFO(staging, "Y");

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=comedi,mite,ni_tiocmd,ni_tio,8255,comedi_fc";

MODULE_ALIAS("pci:v00001093d00000162sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001170sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001180sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001190sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000011B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000011C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000011D0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001270sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001330sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001340sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001350sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000014E0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000014F0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001580sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000015B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001880sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00001870sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000018B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000018C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002410sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002420sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002430sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002890sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000028C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002A60sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002A70sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002A80sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002AB0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002B80sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002B90sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002C80sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d00002CA0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070AAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070ABsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070ACsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070AFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070B8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070BCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070BDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070BFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070C0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070F2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000070F3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d0000710Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d0000716Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d0000716Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d0000717Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000071BCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d0000717Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001093d000072E8sv*sd*bc*sc*i*");
