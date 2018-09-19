CLANG=clang-3.4

%.bc:  %.c
	$(CLANG) -Ibasic/ -c -emit-llvm -g -D MAIN_FUNC -o  $@ $<

%.run: %.bc	
	rm -rf $@
	klee -libc=uclibc -max-time=20 -output-dir=$@ $<

loops:=$(filter-out main.c,$(wildcard *.c))

all: $(loops:.c=.run)

