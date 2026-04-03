# Write a shell script to create three files.
#!/bin/bash
for x in f11 f12 f13
do 
	touch $x
	echo "File Created"
done

