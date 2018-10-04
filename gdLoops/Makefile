CLANG=clang-3.4
KLEE_FLAGS:=-search=dfs -use-merge -exit-on-error-type=Assert -libc=uclibc -only-output-states-covering-new -rewrite-equalities=false  -watchdog

TIME=20
PROGRAM_SIZE=10
EXAMPLE_SIZE=4

%.bc:  %.c
	$(CLANG) -Ibasic/ -c -emit-llvm -g -D MAIN_FUNC -o  $@ $<

%.synth.bc:  %.c
	$(CLANG) -Isynthesize/ -c -emit-llvm -g -D MAIN_FUNC -DPROGRAM_MAX_SIZE=$(PROGRAM_SIZE) -o $@ $<

%.verify.bc:  %.c
	$(CLANG) -Iverify/ -c -emit-llvm -g -D MAIN_FUNC -DPROGRAM_MAX_SIZE=$(PROGRAM_SIZE) -DEXAMPLE_MAX_SIZE=$(EXAMPLE_SIZE) -o $@ $<

%.run: %.bc	
	rm -rf $@
	klee -libc=uclibc -max-time=20 -output-dir=$@ $<

%.synth: %.synth.bc	
	rm -rf $@
	klee $(KLEE_FLAGS) -max-time=$(TIME) -write-paths -output-dir=$@ $< | tee $@.output 
	mv $@.output $@/program

%.prog: %.synth
	cat  $</program | tr '\n' '\032' | grep -a 'FOUND the program' |	sed 's/.*FOUND the program: \(.\+\)END!.*/\1/g' | tr '\032' '\n' > $@ 
	test -s $@ || rm -f $@


PROG_PREF:=

%.verify: %.verify.bc	$(PROG_PREF)%.prog
	rm -rf $@
	klee $(KLEE_FLAGS) -max-time=$(TIME) -output-dir=$@ $< "$(word 2,$^)" 
	test -e $@/test*.assert.err && touch $@.err || true
	! test -e $@/test*.assert.err


loops:=$(filter-out main.c,$(wildcard *.c))

synth: $(loops:.c=.prog)


progs:=$(wildcard $(PROG_PREF)*.prog)
ver: $(notdir $(progs:.prog=.verify))

all: $(loops:.c=.run)

PERF=/data/Random/perf/linux-4.4.0/tools/perf/perf
%.profile: %.synth.bc
	rm -fr $@
	$(PERF) record -F 99 -a -g -- klee $(KLEE_FLAGS) -max-time=$(TIME) -write-paths -output-dir=$@ $<

%.perf: %.profile
	$(PERF) script --pid $(shell grep PID: $</info | cut -f2 -d ' ') > out.perf
	/data/Random/FlameGraph/stackcollapse-perf.pl out.perf > out.folded
	cat out.folded | /data/Random/FlameGraph/flamegraph.pl > klee.svg
