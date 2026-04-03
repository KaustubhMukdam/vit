# Write shell script to find out the reverse number of a given number.
#!/bin/bash
echo "Enter a number"
read num
original=$num
reverse=0
while (( num > 0 ))
do
    remainder=$(( num % 10 ))
    reverse=$(( reverse * 10 + remainder ))
    num=$(( num / 10 ))
done
echo "The reverse of $original is $reverse"

