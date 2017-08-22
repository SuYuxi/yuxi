def read():
	return [int(i) for i in input().split(" ")]
def maxInx(L, pre):
	tempM = [0, 0]
	for i in range(len(L)):
		if(L[i] > tempM[1] and i != pre):
			tempM = [i, L[i]] 
	return tempM[0] if tempM != [0, 0] else pre

(K, T) = read()
A = read()
pre = -1
sameDay = 0
for i in range(K):
	inx = maxInx(A, pre) 
	if(inx == pre):
		sameDay += 1
	A[inx] -= 1
	pre = inx
print(sameDay)
