#!/bin/bash
#Tenth Line
FILE="file.txt"
row=1
while read LINE
do 
	if [ "${row}" -eq 10 ]
	then
		echo ${LINE}
		break
	fi
((row++))
done < ${FILE}
