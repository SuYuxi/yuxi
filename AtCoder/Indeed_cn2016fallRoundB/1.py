def read():
	return [int(i) for i in input().split(" ")]
N = read()[0]
L = read()
num = 0
for i in range(1,N-1):
	if(L[i] > L[i-1] and L[i] > L[i+1]):
		num += 1
print(num)
