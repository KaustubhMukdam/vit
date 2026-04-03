# Write a shell script to print date and time 10 times, once after each second.
#!/bin/bash
for((i=0;i<10;i++))
do
	date
	sleep 1
done
