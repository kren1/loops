#!/bin/bash
OPT=/data/dependencies/llvm-6.0/build/bin/opt
LIB=/data/dependencies/llvm-6.0/build/lib/LLVMLoopFind.so
${OPT} --load ${LIB} -mem2reg -hello -S -o out.ll < $1 > /dev/null
