# Write a shell script to copy file content of one file to another file. Accept files names from command line argument.
#!/bin/bash
touch $1
touch $2
cp $1 $2
cat $1
cat $2
ls -l $1
ls -l $2
