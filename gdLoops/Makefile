CLANG=clang-3.4

%.bc:  %.c
	$(CLANG) -c -emit-llvm -g -D MAIN_FUNC -o  $@ $<

%.run: %.bc	
	klee -libc=uclibc -max-time=20 -output-dir=$@ $<

loops:=$(filter-out main.c,$(wildcard *.c))

all: $(loops:.c=.run)

