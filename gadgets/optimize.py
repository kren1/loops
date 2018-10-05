#!/usr/bin/python3
# --- Load GPyOpt
from GPyOpt.methods import BayesianOptimization
import numpy as np
import os
from subprocess import call, DEVNULL, Popen, PIPE


vocab = "MRCPNBZXEIFVS"

def snd(x): return x[1]
def fst(x): return x[0]

# --- Define your problem
def f(x): 
  TIME=300
  PROG_SIZE=5
  for bitvec in x:
      print(bitvec)
      selected_vocab = list(map(fst,filter(snd, zip(vocab, bitvec))))
      selected_vocab = "".join(selected_vocab)
      print(selected_vocab)
#      selected_vocab = "MRPNBZIF"
#      selected_vocab = "PNXF"

      gadgets = " ".join(selected_vocab)
      call(["make", "GADGETS={}".format(gadgets), 
                    "TIME={}".format(TIME), 
                    "PROG_SIZE={}".format(PROG_SIZE)],
           stdout=DEVNULL,
           stderr=DEVNULL)


      dirname="exp-{}-{}s-{}".format(selected_vocab, TIME, PROG_SIZE)
      command="ls {}/*.prog | wc -l 2>&1".format(dirname)
      proc = Popen(command, stdout=PIPE, shell=True)
      (out,err) = proc.communicate()
      synthesized_programs = int(out.decode("utf-8"))
      print(synthesized_programs)
      return synthesized_programs

domain = [{'name': "var-" + gadget, 'type': 'discrete', 'domain': (0,1)} for gadget in vocab ]
print(domain)

seed(123456)

myBopt = BayesianOptimization(f, domain, maximize=True, exact_feval = True)
myBopt.run_optimization(max_iter=15)
myBopt.save_report("report")
myBopt.save_evaluations("evals")
myBopt.plot_convergence("convergence.png")
