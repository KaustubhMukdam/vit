# a12.sh
# Write a shell script to perform arithmetic operation of float data.
#!/bin/bash
# Addition of num1 and num2
echo "Enter number 1"
read num1
echo "Enter number 2"
read num2

#Addition of num1 and num2
add=`echo $num1 + $num2 | bc`
echo "Addition of $num1 and $num2 is $add"

# Subtraction of num1 and num2
sub=`echo $num2 - $num1 | bc`
echo "Subtraction of $num2 and $num1 is $sub"

# Multiplication of num1 and num2
multi=`echo "$num1 * $num2" | bc`
echo "Multiplication of $num1 and $num2 is $multi"

# Division of num1 and num2
div=`echo $num2 / $num1 | bc`
echo "Division of $num1 and $num2 is $div"

# Exponent of num1
exp=`echo $num1 ^ $num2 | bc`
echo "$num1 to the power $num2 is $exp"
