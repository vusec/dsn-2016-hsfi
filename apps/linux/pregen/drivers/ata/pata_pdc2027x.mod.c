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
"depends=";

MODULE_ALIAS("pci:v0000105Ad00004D68sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Ad00004D69sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Ad00006268sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Ad00006269sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Ad00001275sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Ad00005275sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000105Ad00007275sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "E59CD7438C88B94AC781A4F");
