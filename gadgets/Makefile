LOOPS_FOLDER:=../gdLoops
PROGS:=$(wildcard $(LOOPS_FOLDER)/*.c)
TIME=120
PROG_SIZE=5
EXP_NAME=exp-$(shell echo $(GADGETS) | tr -d ' ')-$(TIME)s-$(PROG_SIZE)

all: $(EXP_NAME)

$(EXP_NAME): $(addprefix $(LOOPS_FOLDER)/, Makefile verify synthesize genResults.sh showFileAndProg.sh)
	rm -rf $@
	mkdir -p $@
	cp $(PROGS) $@
	cp -r $^ $@
	$(MAKE) -C $@ synth TIME=$(TIME) PROGRAM_SIZE=$(PROG_SIZE) GADGETS='$(GADGETS)' 
