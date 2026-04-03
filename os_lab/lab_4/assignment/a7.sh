# Write a shell script to create two files. Accept file names from user.
#!/bin/bash
# Method-1 using read function
echo "Enter file name 1"
read filename1
echo "Enter file name 2"
read filename2
touch filename1
touch filename2
ls -l filename1
ls -l filename2
#Method-2 using Command line arguments
touch $1
touch $2
ls -l $1
ls -l $2
