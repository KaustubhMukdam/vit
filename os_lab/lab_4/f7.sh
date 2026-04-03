# Arithmetic Operations
# 1. Addition of 2 numbers
#!/bin/bash
echo "Enter number 1"
read num1
echo "Enter number 2"
read num2
add=`expr $num1 + $num2`
add_1=$[num1+num2]
add_2=$[num1 + num2]
add_3=$((num1+num2))
add_4=`echo $num1 + $num2 | bc`
echo "add = $add"
echo "add 1 = $add_1"
echo "add 2 = $add_2"
echo "add 3 = $add_3"
echo "add 4 = $add_4"
