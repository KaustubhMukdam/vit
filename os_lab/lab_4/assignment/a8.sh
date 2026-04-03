# Write a shell script to create two directories. Accept directories name from Command line.
#!/bin/bash
touch $1
touch $2
mkdir $1
mkdir $2
ls -l $1
ls -l $2
