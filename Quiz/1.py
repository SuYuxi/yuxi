#Define function that getting the longest substring that meets mode requirement
def getLongestSubString(inputStr, mode = 'Asc'):
#Partial function to dynamically create compare function according to mode
	def partialfunc(mode):
		if(mode == 'Asc'):
			def compare(a, b):
				return a > b
			return compare
		elif(mode == 'Desc'):
			def compare(a, b):
				return a < b
			return compare
		else:	
			def compare(a, b):
				return a == b
			return compare

#Validate if the inputs are legal, otherwise throw an input error
	if(type(inputStr) != str):
		raise TypeError('Input error! Input type can only be "String"!')
	if(mode not in ['Asc', 'Desc', 'Equal']):
		raise ValueError('Mode error! Mode can only be "Asc", "Desc" or "Equal"!')
	inputLength = len(inputStr)
	if(inputLength <= 1):
		return inputStr
#Validate if the inputs only include digits or only include alphabets, otherwise throw an input error
	flag = [0, 0] 
	for char in inputStr:  
		charcode = ord(char)
		if(charcode >= 48 and charcode <= 57):
			flag[0] = 1
		elif((charcode >= 97 and charcode <= 122) or (charcode >= 65 and charcode <= 90)):
			flag[1] = 1
		else:
			raise ValueError('Input error! Input string can only include digits or only include alphabets!')
		if(flag[0] and flag[1]):
			raise ValueError('Input error! Input string can only include digits or only include alphabets!')
#Get the corresponding compare function by using partial function
	compare = partialfunc(mode)
#Use Two Pointer algorithm to get the longest substring that meets mode requirement
	left, right = 0, 0
	maxlen = 0
	postions = []
	while(left < inputLength):
		right += 1
		while(right < inputLength):
			if(compare(inputStr[right], inputStr[right-1])):
				right += 1
			else:
				break
		subStrLen = right - left
		if(subStrLen > maxlen):
			maxlen = subStrLen
			positions = [left]
		elif(subStrLen == maxlen):
			positions.append(left)
		left = right
	longestSubStr = set() 
	for pos in positions:
		longestSubStr.add(inputStr[pos:pos+maxlen])
	return list(sorted(longestSubStr))

#Main program that call "getLongestSubString" function to get the Longest Sub String with expected mode
mode = input('Please input process mode from "Asc", "Desc" or "Equal" (without quotation mark)\n')
inputData = input('Please input a string to retrieve the longest substring\n')
longestSubStr = getLongestSubString(inputData, mode)
print('The longest \"{0} Value Part String\":'.format(mode))
for subStr in longestSubStr:
	print(subStr)
