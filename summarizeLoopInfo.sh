#!/bin/bash
UTILITY_NAME=${1%.loopinfo}
NUM_LOOPS=$(grep loop $1 | wc -l)
NUM_WRITE_LOOPS=$(grep "write loop" $1 | wc -l)
NUM_OUTER_LOOPS=$(grep "Non empty" $1 | wc -l)
let "NUM_INNER_LOOPS=$NUM_LOOPS - $NUM_OUTER_LOOPS"
POINTER_CALLS=$(grep "pointer call" $1 | wc -l)

echo "$UTILITY_NAME   $NUM_LOOPS   $NUM_INNER_LOOPS   $POINTER_CALLS   $NUM_WRITE_LOOPS "
