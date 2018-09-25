CLANG=clang-3.4
KLEE_FLAGS:=-search=dfs -use-merge -exit-on-error-type=Assert -libc=uclibc -only-output-states-covering-new 
TIME=20

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
	klee $(KLEE_FLAGS) -max-time=$(TIME) -write-paths -output-dir=$@ $< | tee $@.output 
	mv $@.output $@/program

%.prog: %.synth
	grep -a 'FOUND the program' $</program > $@ || rm $@
	sed -i 's/FOUND the program: \(.\+\)END!/\1/g' $@ 

PROG_PREF:=

%.verify: %.verify.bc	$(PROG_PREF)%.prog
	rm -rf $@
	klee $(KLEE_FLAGS) -output-dir=$@ $< "$(word 2,$^)" 
	test -e $@/test*.assert.err && touch $@.err
	! test -e $@/test*.assert.err


loops:=$(filter-out main.c,$(wildcard *.c))

synth: $(loops:.c=.prog)


progs:=$(wildcard $(PROG_PREF)*.prog)
ver: $(notdir $(progs:.prog=.verify)))

all: $(loops:.c=.run)

