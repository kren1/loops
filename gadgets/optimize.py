#!/usr/bin/python3
# --- Load GPyOpt
from GPyOpt.methods import BayesianOptimization
import numpy as np
import os
from subprocess import call, DEVNULL

vocab = "MRCPNBZXEIF"

def snd(x): return x[1]
def fst(x): return x[0]

# --- Define your problem
def f(x): 
  TIME=20
  PROG_SIZE=5
  for bitvec in x:
      print(bitvec)
      selected_vocab = list(map(fst,filter(snd, zip(vocab, bitvec))))
      selected_vocab = "".join(selected_vocab)
#      selected_vocab = "MRPNBZIF"

      gadgets = " ".join(selected_vocab)
      call(["make", "GADGETS={}".format(gadgets), 
                    "TIME={}".format(TIME), 
                    "PROG_SIZE={}".format(PROG_SIZE)],
           stdout=DEVNULL,
           stderr=DEVNULL)


      dirname="exp-{}-{}s-{}".format(selected_vocab, TIME, PROG_SIZE)
      command="ls {}/*.prog | wc -l".format(dirname)
      synthesized_programs=os.system(command)
      print(synthesized_programs)
      return synthesized_programs

domain = [{'name': "var-" + gadget, 'type': 'discrete', 'domain': (0,1)} for gadget in vocab ]
print(domain)

myBopt = BayesianOptimization(f, domain, maximize=True)
myBopt.run_optimization(max_iter=15)
myBopt.save_report("report")
myBopt.save_evaluations("evals")
myBopt.plot_convergence("convergence.png")
