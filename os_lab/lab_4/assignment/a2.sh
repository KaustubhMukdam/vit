# Write a shell script to assign value to the variable? Display value with and without and without $
#!/bin/bash
val=10
echo "Val = $val"
echo "Val = val"
export VALUE=3
printenv VALUE
