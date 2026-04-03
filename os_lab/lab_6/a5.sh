# Write a shell script to count the number of file names passed at command line.
#!/bin/bash
count=0
for x in $@
do
	if [ -f $x ]
	then
		count=`expr $count + 1`
	fi
done
echo "Number of files = $count"
