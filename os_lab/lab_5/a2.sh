# Write a shell script to check if a file exists. If not, then create it.
#!/bin/bash
echo "Enter file name"
read filename
if [ -r $filename ]
then
	echo "File exists"
else
	touch $filename
	echo "File created"
	ls
fi

