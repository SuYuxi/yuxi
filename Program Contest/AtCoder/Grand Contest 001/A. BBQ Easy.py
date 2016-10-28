num = int(input())
str = input()
Li = list(map(int,str.split(' ')))
Li.sort()
sum = 0 
if len(Li)%2 == 1:
	Li = Li[1:]
for i in range(0,len(Li),2):
	sum += Li[i]
print(sum)
