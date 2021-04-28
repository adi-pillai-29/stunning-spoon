#!/bin/bash

#Adi Pillai, arp3np@virginia.edu, 04/09/2021, "averagetime.sh"

echo "enter the exponent for counter.cpp:"
read exp

sum=0
iteration=5
if [[ "$1" == "quit" ]] ; then
    exit 1;
else
    for i in `seq 1 $iteration`; do
	RUNNING_TIME=`./a.out $exp | tail -1`
	sum=$(($sum + $RUNNING_TIME))
	echo "Running iteration $i..."
	echo "time taken: $RUNNING_TIME ms"
    done
fi

echo "$iteration iterations took $sum ms"
average=$(($sum / 5))
echo "Average time was $average ms"
