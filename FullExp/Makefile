LOOPS_FOLDER:=../gdLoops
PROGS:=$(wildcard $(LOOPS_FOLDER)/*.c)
IMPORTANT_FILES:=Makefile verify synthesize genResults.sh showFileAndProg.sh compare nativeBenchmark
IMPORTANT_FILES+=uploadCexp.sh uploadNativeRuns.sh timingResults.sh printTodo.sh runComapreExp.sh

PARA:=

all: .baseExperiment .verifyExperiment .strCompareExperiment .nativeCompareExperiment


%.gdLoops: $(addprefix $(LOOPS_FOLDER)/, $(IMPORTANT_FILES)) 
	rm -rf $@
	mkdir -p $@
	cp $(PROGS) $@
	cp -r $^ $@

.baseExperiment: baseExperiment.gdLoops
	make -C $< TIME=20 PROGRAM_SIZE=10 EXAMPLE_SIZE=4 GADGETS='M R C P N B Z X E S I F' progs $(PARA)
	touch $@

.verifyExperiment: baseExperiment.gdLoops .baseExperiment
	make -C $< TIME=20 PROGRAM_SIZE=10 EXAMPLE_SIZE=7 GADGETS='M R C P N B Z X E S I F' ver $(PARA)
	touch $@

.strCompareExperiment: baseExperiment.gdLoops .baseExperiment
	make -C $< TIME=20 PROGRAM_SIZE=10 EXAMPLE_SIZE=7 GADGETS='M R C P N B Z X E S I F' comp $(PARA)
	touch $@

.nativeCompareExperiment: baseExperiment.gdLoops .baseExperiment
	make -C $< native_comp $(PARA)
	touch $@

.PHONY: clean all
clean:
	rm -rf .baseExperiment baseExperiment.gdLoops	
	rm -rf .verifyExperiment .strCompareExperiment .nativeCompareExperiment
	
