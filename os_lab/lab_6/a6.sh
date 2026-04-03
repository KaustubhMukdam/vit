# Write a shell script to accept and display array. Assume array consist 5 number.
#!/bin/bash
echo "Enter Array"
for((i=0;i<5;i++))
do
	read arr[i]
done
echo "Entered Array"
for((i=0;i<5;i++))
do
	echo ${arr[i]}
done
