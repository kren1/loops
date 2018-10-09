#!/usr/bin/python3
# --- Load GPyOpt
#from GPyOpt.methods import BayesianOptimization
import numpy as np
import os
import re
from subprocess import call, DEVNULL, Popen, PIPE
from sklearn.manifold import TSNE
import matplotlib.pyplot as plt


vocab = "MRCPNBZXEIFVS"

def snd(x): return x[1]
def fst(x): return x[0]

# --- Define your problem
def f(x): 
  TIME=3600
  PROG_SIZE=7
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
           stderr=DEVNULL
           )


      dirname="exp-{}-{}s-{}".format(selected_vocab, TIME, PROG_SIZE)
      command="ls {}/*.prog | wc -l 2>&1".format(dirname)
      proc = Popen(command, stdout=PIPE, shell=True)
      (out,err) = proc.communicate()
      synthesized_programs = int(out.decode("utf-8"))
      print(synthesized_programs)
      return synthesized_programs

#domain = [{'name': "var-" + gadget, 'type': 'discrete', 'domain': (0,1)} for gadget in vocab ]
#print(domain)
#
#myBopt = BayesianOptimization(f, domain, maximize=True, exact_feval = True)
#myBopt.run_optimization(max_iter=35)
#myBopt.save_report("report")
#myBopt.save_evaluations("evals")
#myBopt.plot_convergence("convergence.png")

def vocabToVector(v):
  lst = iter(v)
  c = next(lst)
  vector = []
  chrs = []
  for ch in vocab:
      vector.append(1 if ch == c else 0)
      if ch == c:
          chrs.append(c)
          try:
            c = next(lst)
          except StopIteration:
            c = '0'
  print(vector)
  return vector


  


def getData():
  subdirs = next(os.walk('.'))[1] 
  data = []
  for d in subdirs:
      m = re.search("exp-([A-Z]+)-([0-9]+)s-([0-9]+)", d)
      if m:
          vocab, time, progsize = m.group(1), m.group(2), m.group(3)
          command="ls {}/*.prog | wc -l 2>&1".format(d)
          proc = Popen(command, stdout=PIPE, shell=True)
          (out,err) = proc.communicate()
          synthesized_programs = int(out.decode("utf-8"))
          data.append((vocabToVector(vocab), int(time), int(progsize), synthesized_programs, vocab))
  return np.array(data)



data = getData()
vector, time, ps, synthesized_programs, vocab = (data[data[:,1] == 300, i] for i in range(5))
a = [b for b in vector]
vector = np.array(a)
print(vocab)

tsne = TSNE()
tsne_results = tsne.fit_transform(vector)
x,y = np.rollaxis(tsne_results,1)

a = plt.scatter(x,y, c=synthesized_programs)
for i, txt in enumerate(vocab):
    plt.annotate(txt, (x[i], y[i]))
plt.colorbar()
plt.show()

