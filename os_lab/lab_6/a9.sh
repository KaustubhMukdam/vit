#!/bin/bash
echo "Enter Array"
for ((i=0; i<5; i++))
do
        read arr[i]
done
for (( i=0; i<5; i++ ))
do
    for (( j=0; j<5-i-1; j++ ))
    do
        if (( arr[j] > arr[j+1] ))
        then
            temp=${arr[j]}
            arr[j]=${arr[j+1]}
            arr[j+1]=$temp
        fi
    done
done
echo "Array in Ascending Order:  ${arr[@]}"
for (( i=0; i<5; i++ ))
do
    for (( j=0; j<5-i-1; j++ ))
    do
        if (( arr[j] < arr[j+1] ))
        then
            temp=${arr[j]}
            arr[j]=${arr[j+1]}
            arr[j+1]=$temp
        fi
    done
done
echo "Array in Descending Order:  ${arr[@]}"
