LOOPS_FOLDER:=../gdLoops
PROGS:=$(wildcard $(LOOPS_FOLDER)/*.c)
TIME=120
PROG_SIZE=5
IMPORTANT_FILES:=Makefile verify synthesize genResults.sh showFileAndProg.sh compare nativeBenchmark

all: $(EXP_NAME)

$(EXP_NAME): $(addprefix $(LOOPS_FOLDER)/, $(IMPORTANT_FILES)) 
	rm -rf $@
	mkdir -p $@
	cp $(PROGS) $@
	cp -r $^ $@
	mv $(EXP_NAME)/synthesize/interpreter.c $(EXP_NAME)/synthesize/interpreter.c.backup
	./transform.py < $(EXP_NAME)/synthesize/interpreter.c.backup > $(EXP_NAME)/synthesize/interpreter.c
	$(MAKE) -C $@ synth TIME=$(TIME) PROGRAM_SIZE=$(PROG_SIZE) GADGETS='$(GADGETS)'  -j4
