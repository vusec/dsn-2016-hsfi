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
"depends=hid";

MODULE_ALIAS("hid:b0003g0002v00000596p00000500");
MODULE_ALIAS("hid:b0003g0002v00000596p00000502");
MODULE_ALIAS("hid:b0003g0002v00000596p00000506");
MODULE_ALIAS("hid:b0003g0002v00002101p00001011");
MODULE_ALIAS("hid:b0003g0002v000003EBp0000211C");
MODULE_ALIAS("hid:b0003g0002v000003EBp00002118");
MODULE_ALIAS("hid:b0003g0002v00002453p00000100");
MODULE_ALIAS("hid:b0003g0002v00002087p00000A01");
MODULE_ALIAS("hid:b0003g0002v00002087p00000A02");
MODULE_ALIAS("hid:b0003g0002v00002087p00000B03");
MODULE_ALIAS("hid:b0003g0002v00002087p00000F01");
MODULE_ALIAS("hid:b0003g0002v00002247p00000001");
MODULE_ALIAS("hid:b0003g0002v00001FF7p00000013");
MODULE_ALIAS("hid:b0003g*v000004B4p0000C001");
MODULE_ALIAS("hid:b0003g0002v00007374p00001201");
MODULE_ALIAS("hid:b0003g0002v00000EEFp0000480D");
MODULE_ALIAS("hid:b0003g0002v00000EEFp0000480E");
MODULE_ALIAS("hid:b0003g0002v00000EEFp00007207");
MODULE_ALIAS("hid:b0003g0002v00000EEFp0000720C");
MODULE_ALIAS("hid:b0003g0002v00000EEFp00007224");
MODULE_ALIAS("hid:b0003g0002v00000EEFp0000722A");
MODULE_ALIAS("hid:b0003g0002v00000EEFp0000725E");
MODULE_ALIAS("hid:b0003g0002v00000EEFp00007262");
MODULE_ALIAS("hid:b0003g0002v00000EEFp0000726B");
MODULE_ALIAS("hid:b0003g0002v00000EEFp000072A1");
MODULE_ALIAS("hid:b0003g0002v00000EEFp000072AA");
MODULE_ALIAS("hid:b0003g*v00000EEFp000072C4");
MODULE_ALIAS("hid:b0003g*v00000EEFp000072D0");
MODULE_ALIAS("hid:b0003g0002v00000EEFp000072FA");
MODULE_ALIAS("hid:b0003g0002v00000EEFp00007302");
MODULE_ALIAS("hid:b0003g0002v00000EEFp00007349");
MODULE_ALIAS("hid:b0003g0002v00000EEFp000073F7");
MODULE_ALIAS("hid:b0003g0002v00000EEFp0000A001");
MODULE_ALIAS("hid:b0003g0002v000004E7p00000022");
MODULE_ALIAS("hid:b0003g0002v000025B5p00000002");
MODULE_ALIAS("hid:b0003g0002v00000DFCp00000003");
MODULE_ALIAS("hid:b0003g0002v00000DFCp00000100");
MODULE_ALIAS("hid:b0005g0002v000025B6p00000002");
MODULE_ALIAS("hid:b0003g0002v00001AADp0000000F");
MODULE_ALIAS("hid:b0003g0002v000022EDp00001010");
MODULE_ALIAS("hid:b0003g0002v00001CB6p00006650");
MODULE_ALIAS("hid:b0003g0002v00001CB6p00006651");
MODULE_ALIAS("hid:b0003g0002v0000222Ap00000001");
MODULE_ALIAS("hid:b0003g0002v00006615p00000070");
MODULE_ALIAS("hid:b0003g0002v00001FD2p00000064");
MODULE_ALIAS("hid:b0003g0002v0000202Ep00000006");
MODULE_ALIAS("hid:b0003g0002v0000202Ep00000007");
MODULE_ALIAS("hid:b0003g0002v00000486p00000185");
MODULE_ALIAS("hid:b0003g0002v00000486p00000186");
MODULE_ALIAS("hid:b0003g0002v0000062Ap00007100");
MODULE_ALIAS("hid:b0003g0002v00001870p0000010D");
MODULE_ALIAS("hid:b0003g0002v000004DAp00001044");
MODULE_ALIAS("hid:b0003g0002v000004DAp0000104D");
MODULE_ALIAS("hid:b0003g0002v00000603p00000600");
MODULE_ALIAS("hid:b0003g0002v000014E1p00003500");
MODULE_ALIAS("hid:b0003g0002v0000093Ap00008001");
MODULE_ALIAS("hid:b0003g0002v0000093Ap00008002");
MODULE_ALIAS("hid:b0003g0002v0000093Ap00008003");
MODULE_ALIAS("hid:b0003g0002v000020B3p00000A18");
MODULE_ALIAS("hid:b0003g0002v00002087p00000703");
MODULE_ALIAS("hid:b0003g0002v00000408p00003000");
MODULE_ALIAS("hid:b0003g0002v00000408p00003001");
MODULE_ALIAS("hid:b0003g0002v00000408p00003008");
MODULE_ALIAS("hid:b0003g0002v00001F87p00000002");
MODULE_ALIAS("hid:b0003g0002v00000483p00003261");
MODULE_ALIAS("hid:b0003g0002v00001403p00005001");
MODULE_ALIAS("hid:b0003g0002v00001784p00000016");
MODULE_ALIAS("hid:b0003g0002v00001E5Ep00000313");
MODULE_ALIAS("hid:b0003g0002v0000227Dp00000709");
MODULE_ALIAS("hid:b0003g0002v0000227Dp00000A19");
MODULE_ALIAS("hid:b0003g0002v00002505p00000220");
MODULE_ALIAS("hid:b0003g0002v00001477p00001006");
MODULE_ALIAS("hid:b0003g0002v00001477p00001007");
MODULE_ALIAS("hid:b0003g0002v00001477p0000100E");
MODULE_ALIAS("hid:b0003g0002v00001477p00001021");
MODULE_ALIAS("hid:b0003g0002v00001477p00001023");
MODULE_ALIAS("hid:b0003g0002v00001477p00001022");
MODULE_ALIAS("hid:b0003g0002v00001477p00001024");
MODULE_ALIAS("hid:b0003g0002v00001477p00001026");
MODULE_ALIAS("hid:b0003g0002v00001477p00001025");
MODULE_ALIAS("hid:b0003g0002v000014C8p00000005");
MODULE_ALIAS("hid:b*g0002v*p*");
