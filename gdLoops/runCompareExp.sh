#!/bin/bash

for i in $(seq 6 2 22); do
    OUTPUT_NAME=compare-${i}.cexp
    make comp_clean 
    make comp EXAMPLE_SIZE=$i TIME=240 -j3
    cat *.compare >  ${OUTPUT_NAME}
    sed -i "s/$/ $i/" $OUTPUT_NAME 
done
