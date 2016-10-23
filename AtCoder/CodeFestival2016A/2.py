#B-Friendly Rabbits
num = int(input())
str = input()
Li = list(map(int,str.split(' ')))
CoupleNum = 0
for pointer in range(len(Li)):
	ai = Li[pointer]
	if (ai > pointer+1):
		if (Li[ai-1]==pointer+1):
			CoupleNum += 1
print(CoupleNum)
