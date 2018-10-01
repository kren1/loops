LOOPS_FOLDER:=../gdLoops
SYNTHESIZED_LOOPS:=$(wildcard $(LOOPS_FOLDER)/*.prog)
SYNTHESIZED_PROGS=$(notdir $(SYNTHESIZED_LOOPS))
SYNTH_PROGS:=$(SYNTHESIZED_PROGS:.prog=.c)

%.dir: $(addprefix $(LOOPS_FOLDER)/, Makefile verify synthesize genResults.sh showFileAndProg.sh)
	rm -rf $@
	mkdir -p $@
	cp $(addprefix $(LOOPS_FOLDER)/, $(SYNTH_PROGS)) $@
	cp -r $^ $@

%.dir/synth: %.dir
	$(MAKE) -C $(dir $@) synth TIME=300 PROGRAM_SIZE=$(basename $<)
	touch $@

do: $(addsuffix .dir/synth,$(shell seq 1 10))
	
clean:
	rm -rf *.dir
