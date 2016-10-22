import copy
def read():
	return [int(i) for i in input().split(" ")]
(N, M) = read()
def score(A):
	ans = 0
	for i in range(len(A)):
		ans += (i + 1) * A[i]
	return ans
A = read()
L = []
for i in range(M):
	L.append(read())
maxval = [0]
def DFS(A, L, maxval):
	for i in L:
		temp = copy.copy(A)
		tempL = copy.deepcopy(L) 
		tempL.remove(i)
		temp[i[0]-1:i[1]] = temp[i[0]-1:i[1]][::-1] 
		maxval[0] = max(maxval[0], score(temp))
		DFS(temp, tempL, maxval) 
	return 
DFS(A, L, maxval)
print(maxval[0])
