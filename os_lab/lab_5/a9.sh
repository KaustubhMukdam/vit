# Write a shell script to check if the present month is Feb   or not. Use date command to get present month.
#!/bin/bash
currentmonth=$(date +%b)
if [ $currentmonth = "Feb" ]
then
	echo "Current month is Feb"
else
	echo "Current month is $currentmonth"
fi

