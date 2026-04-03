# Write a shell script to create five directories. Accept the name of directories from command line.
#!/bin/bash
for x in $*
do
	mkdir $x
	echo "Directory created"
done

