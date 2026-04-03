# Write a shell script to print long list of all file’s names passed at command line.
#!/bin/bash
# To check if atleast one argument is passed or not
if [ $# -eq 0 ] 
then
    echo "No file name added in argument"
    exit 1
fi
for x in $@
do
	if [ -f $x ]
	then
		ls -al $x
	else
		echo "File not found"
	fi
done
