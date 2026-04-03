# Write a shell script to check number entered by the user is greater than 10.
#!/bin/bash
echo "Enter a number"
read num1
if [ $num1 -gt 10 ]
then
	echo "Number is greater than 10"
else
	echo "Number is less than 10"
fi

