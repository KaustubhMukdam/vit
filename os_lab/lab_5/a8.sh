# Write a shell script to check whether file is exists and file is readable.
#!/bin/bash
echo "Enter file name"
read filename
if [ -f $filename ] && [ -r $filename ]
then
	echo "File exists and it is readable"
elif [ -f $filename ] && [ ! -r $filename ]
then
        echo "File exists but it is not readable"

else
	echo "File does not exists"
fi
