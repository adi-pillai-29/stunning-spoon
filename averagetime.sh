#!/bin/bash

#Adi Pillai, arp3np@virginia.edu, 03/30/2021, "averagetime.sh"

#read in the file names
echo "Please enter dictionary: "
read dict

echo "Please enter grid: "
read grid

RUNNING_TIME1=`./a.out $dict $grid | tail -1`
RUNNING_TIME2=`./a.out $dict $grid | tail -1`
RUNNING_TIME3=`./a.out $dict $grid | tail -1` #running the program 5 times and tracking run times
RUNNING_TIME4=`./a.out $dict $grid | tail -1`
RUNNING_TIME5=`./a.out $dict $grid | tail -1`
echo $(($(($(($((${RUNNING_TIME1}+${RUNNING_TIME2})) + $((${RUNNING_TIME3} + ${RUNNING_TIME4})))) + ${RUNNING_TIME5})) / 5)) 




