CLANG=clang-3.4
KLEE_FLAGS:=-search=dfs -optimize -use-merge -exit-on-error-type=Assert -libc=uclibc -only-output-states-covering-new 

%.bc:  %.c
	$(CLANG) -Ibasic/ -c -emit-llvm -g -D MAIN_FUNC -o  $@ $<

%.synth.bc:  %.c
	$(CLANG) -Isynthesize/ -c -emit-llvm -g -D MAIN_FUNC -o  $@ $<

%.verify.bc:  %.c
	$(CLANG) -Iverify/ -c -emit-llvm -g -D MAIN_FUNC -o  $@ $<

%.run: %.bc	
	rm -rf $@
	klee -libc=uclibc -max-time=20 -output-dir=$@ $<

%.synth: %.synth.bc	
	rm -rf $@
	klee $(KLEE_FLAGS) -max-time=60 -output-dir=$@ $< | tee $@.output 
	mv $@.output $@/program

%.prog: %.synth
	grep -a 'FOUND the program' $</program > $@
	sed -i 's/FOUND the program: \(.\+\)END!/\1/g' $@

%.verify: %.verify.bc	%.prog
	rm -rf $@
	klee $(KLEE_FLAGS) -output-dir=$@ $< $(shell cat $(word 2, $^))

loops:=$(filter-out main.c,$(wildcard *.c))

synth: $(loops:.c=.prog)

all: $(loops:.c=.run)

