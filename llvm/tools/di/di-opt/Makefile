ROOT=../../../..
include $(ROOT)/Makefile.inc
include $(ROOT)/llvm/Makefile.inc
include $(ROOT)/llvm/di-passes/Makefile.def.inc

HEADERS += $(wildcard include/*.h) $(wildcard $(LLVMINC)/common/opt/*.h) $(wildcard $(ROOT)/llvm/di-passes/include/*.h)

INCLUDES += -I$(ROOT)/llvm/di-passes/include

LDFLAGS += -ldl -lrt -rdynamic

SRCS = di-opt.cpp

all: di-opt

di-opt: di-opt.o
	$(QUIET) $(ECHO) "  [LINK] $@"
	$(QUIET) $(CXX) $(CFLAGS) -o $@ $@.o $(LDFLAGS) $(LIBS)

%.o: %.cpp $(HEADERS)
	$(QUIET) $(ECHO)  "  [C++] $<"
	$(QUIET) $(CXX) $(CFLAGS) $(INCLUDES) -c -o $@ $<

install: $(INSTALL_DIR)/di-opt

$(INSTALL_DIR)/di-opt: di-opt
	install -c -D -m 744 $? $@

clean:
	rm -f *.o di-opt

distclean: clean
	rm -f $(INSTALL_DIR)/di-opt

