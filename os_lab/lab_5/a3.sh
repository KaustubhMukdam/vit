#!/bin/bash
if [ -d $1 ]
then
	echo "Directory Present"
	ls
else
	mkdir $2
	echo "Directory Created"
	ls
fi

