# Write a shell script to check whether file or directory exists.
#!/bin/bash
echo "Enter directory name"
read dirname
if [ -d $dirname ]
then
	echo "Directory exist"
else
	echo "Directory does not exist"
fi
