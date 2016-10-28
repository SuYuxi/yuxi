str = input()
num = list(map(int,str.split(' ')))
if ((num[0]%2)and(num[1]%2)and(num[2]%2))==0:
	print(0)
else:
	num.sort()
	print(num[0]*num[1])
