#Fault injection server
#
ifdef CONFIG_LTO
obj-y += edfi.o
edfi-y := edfi_ctl_server.o edfi_lib.o edfi_hyper.o
else
obj-m += edfi_server.o
edfi_server-objs := edfi_ctl_server.o \
		edfi_lib.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

endif
