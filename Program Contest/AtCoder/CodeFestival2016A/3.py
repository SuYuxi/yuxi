#C-Next Letter
str = input()
K = int(input())
tempK = K
result = ""
for i in range(len(str)-1):
	changeNum = 122-ord(str[i])+1
	if (changeNum <= tempK and str[i] != "a"):
		result += "a"
		tempK -= changeNum
	else:
		result += str[i]
tempK %= 26
if (tempK > 0):
	changeNum = ord(str[-1]) + tempK
	if (changeNum > 122):
		changeNum = changeNum -122 + 97 -1
	else:
		changeNum = changeNum
	result += chr(changeNum)
else:
	result += str[-1]
print(result)
