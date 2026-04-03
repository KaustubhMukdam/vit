# Write a shell script to rename the file name. Accept old filename and new filename from command line argument.
#!/bin/bash
ls -l $1
ls -l $2
mv $1 $2
ls

