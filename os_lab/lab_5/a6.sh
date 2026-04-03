# Write a shell script to read a month name from the user. Check if the name entered is either Feb or March.
#!/bin/bash
echo "Enter month"
read monthname
if [ $monthname = "Feb" ]
then
	echo "Entered month name is Feb"
elif [ $monthname = "March" ]
then
	echo "Entered month name is March"
else
	echo "Entered month name is $monthname"
fi
