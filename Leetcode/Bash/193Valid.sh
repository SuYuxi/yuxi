#!/bin/bash
#Valid phone number 
FILE='file.txt'
Pattern1="^[0-9]{3}-[0-9]{3}-[0-9]{4}$"
Pattern2="^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$"
while read LINE
do
	if [[ "${LINE}" =~ ${Pattern1} ]] || [[ "${LINE}" =~ ${Pattern2} ]]
	then	
		echo "${LINE}"
	fi
done < ${FILE}
#grep '^\([[:digit:]]\{3\}-\|([[:digit:]]\{3\}) \)[[:digit:]]\{3\}-[[:digit:]]\{4\}$' file.txt
#awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/' file.txt
