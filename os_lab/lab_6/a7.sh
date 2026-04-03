#!/bin/bash
echo "Enter Array"
for ((i=0; i<5; i++))
do
        read arr[i]
done

echo "Odd and even array"
for ((i=0; i<5; i++))
do
        
        if [ $((arr[i] % 2)) -eq 1 ]
        then
                echo "Odd value ${arr[i]}"
        else
                echo "Even value ${arr[i]}"
        fi
done
