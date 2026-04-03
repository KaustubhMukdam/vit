# Write a shell script to check arguments passed at command line is whether of a file or directory.
#!/bin/bash
if [ -f $1 ]
then
	echo "This is a file"
elif [ -d $1 ]
then
	echo "This is a directory"
else
	echo "Wrong input"
fi

