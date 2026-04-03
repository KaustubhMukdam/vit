# Write a shell script to check if the current user is root or regular user.
#!/bin/bash
currentuser=$(whoami)
if [ "$currentuser" = "root" ]
then
	echo "Current user is root"
else
	echo "Current user is $currentuser"
fi

