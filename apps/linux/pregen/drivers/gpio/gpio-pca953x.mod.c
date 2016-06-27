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

MODULE_ALIAS("of:N*T*Cnxp,pca9505*");
MODULE_ALIAS("of:N*T*Cnxp,pca9534*");
MODULE_ALIAS("of:N*T*Cnxp,pca9535*");
MODULE_ALIAS("of:N*T*Cnxp,pca9536*");
MODULE_ALIAS("of:N*T*Cnxp,pca9537*");
MODULE_ALIAS("of:N*T*Cnxp,pca9538*");
MODULE_ALIAS("of:N*T*Cnxp,pca9539*");
MODULE_ALIAS("of:N*T*Cnxp,pca9554*");
MODULE_ALIAS("of:N*T*Cnxp,pca9555*");
MODULE_ALIAS("of:N*T*Cnxp,pca9556*");
MODULE_ALIAS("of:N*T*Cnxp,pca9557*");
MODULE_ALIAS("of:N*T*Cnxp,pca9574*");
MODULE_ALIAS("of:N*T*Cnxp,pca9575*");
MODULE_ALIAS("of:N*T*Cmaxim,max7310*");
MODULE_ALIAS("of:N*T*Cmaxim,max7312*");
MODULE_ALIAS("of:N*T*Cmaxim,max7313*");
MODULE_ALIAS("of:N*T*Cmaxim,max7315*");
MODULE_ALIAS("of:N*T*Cti,pca6107*");
MODULE_ALIAS("of:N*T*Cti,tca6408*");
MODULE_ALIAS("of:N*T*Cti,tca6416*");
MODULE_ALIAS("of:N*T*Cti,tca6424*");
MODULE_ALIAS("i2c:pca9505");
MODULE_ALIAS("i2c:pca9534");
MODULE_ALIAS("i2c:pca9535");
MODULE_ALIAS("i2c:pca9536");
MODULE_ALIAS("i2c:pca9537");
MODULE_ALIAS("i2c:pca9538");
MODULE_ALIAS("i2c:pca9539");
MODULE_ALIAS("i2c:pca9554");
MODULE_ALIAS("i2c:pca9555");
MODULE_ALIAS("i2c:pca9556");
MODULE_ALIAS("i2c:pca9557");
MODULE_ALIAS("i2c:pca9574");
MODULE_ALIAS("i2c:pca9575");
MODULE_ALIAS("i2c:max7310");
MODULE_ALIAS("i2c:max7312");
MODULE_ALIAS("i2c:max7313");
MODULE_ALIAS("i2c:max7315");
MODULE_ALIAS("i2c:pca6107");
MODULE_ALIAS("i2c:tca6408");
MODULE_ALIAS("i2c:tca6416");
MODULE_ALIAS("i2c:tca6424");
