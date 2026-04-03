#!/bin/bash
echo "Enter Array"
for ((i=0; i<5; i++))
do
        read arr[i]
done
min=${arr[0]}
max=${arr[0]}
for((i=0;i<5;i++))
do
    if (( arr[i] < min ))
    then
        min=${arr[i]}
    fi
    if (( arr[i] > max ))
    then
        max=${arr[i]}
    fi
done
echo "Minimum Value = $min"
echo "Maximum Value = $max"
