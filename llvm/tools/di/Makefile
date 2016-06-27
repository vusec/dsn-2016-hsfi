ROOT=../../..
include ../../../Makefile.inc

DIRS := di-opt

all install: $(patsubst %,build_%,$(DIRS))

$(patsubst %,build_%,$(DIRS)): DIR = $(subst build_,,$@)
$(patsubst %,build_%,$(DIRS)):
	@echo Building $(DIR) tools...
	$(MAKE) -C $(DIR) install

clean:
	$(foreach DIR, $(DIRS), $(MAKE) -C $(DIR) distclean;)

distclean: clean
