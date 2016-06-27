CFLAGS+= -Wall -Werror -O3

.PHONY: all clean

all: unconditionalize-patch

clean:
	rm -f *.o unconditionalize-patch

unconditionalize-patch: unconditionalize-patch.o

unconditionalize-patch.o: unconditionalize-patch.c ../../include/edfi/unconditionalize/ucpatch.h
