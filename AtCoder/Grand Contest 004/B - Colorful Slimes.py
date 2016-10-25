def read():
	return [int(i) for i in input().split(" ")]
N, x = read()
A = read()
ans = sum(A)
tempcost = ans
BC = A[:]
xt = 0
for i in range(1, N):
	xt += x
	BC = [BC[j - 1] if BC[j - 1] < BC[j] else BC[j] for j in range(N)] 
	tempcost = xt + sum(BC)
	if(ans > tempcost):
		ans = tempcost
print(ans)

def read():
	return [int(i) for i in input().split(" ")]
N, x = read()
A = read()
ans = sum(A)
tempcost = ans
xt = 0
BC = A
for i in range(1, N):
	xt += x
	A = [A[-1]] + A[0:-1] 
	BC = [v if v < BC[i] else BC[i] for (i, v) in enumerate(A)]
	tempcost = xt + sum(BC)
	if(ans > tempcost):
		ans = tempcost
print(ans)
