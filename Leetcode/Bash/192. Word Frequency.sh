#!/bin/bash
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{ print $2, $1 }'

#!/bin/bash
# Word Frequency
FILE="words.txt"
unset Words
unset Freq
IFS=" \|
"
#read -r Words temp  < ${FILE}
WordNum=1
for word in `cat $FILE`
	do
	pointer=0
	while [ "${pointer}" -lt "${#Words[*]}" ]
		do
			if [ "${word}" = "${Words[pointer]}" ]
			then
				((++Freq[pointer]))
				break
			fi
			(( ++pointer ))
	done
	if [ "${pointer}" -eq "${#Words[*]}" ]
	then
		Words[${#Words[*]}]=$word
		Freq[pointer]=1
	fi
done
unset IFS

for ((i=0; i<${#Words[*]}; i++))
do
	for ((k=0; k<${#Words[*]}-1-i; k++))
	do
		if [ "${Freq[k]}" -lt "${Freq[k+1]}" ]
		then
			FreqTemp=${Freq[k]}
			Freq[k]=${Freq[k+1]}
			Freq[k+1]=$FreqTemp
			WordTemp=${Words[k]}
			Words[k]=${Words[k+1]}
			Words[k+1]=$WordTemp
		fi
	done
done	

for ((i=0; i<${#Words[*]}; i++))
do
	echo "${Words[i]} ${Freq[i]}"
done

