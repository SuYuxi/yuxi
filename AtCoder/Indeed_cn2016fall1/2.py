import re
def read():
	return list(map(int, re.split(r'\s+', input())))
(N, M, K) = read()
A = [[]] * N
B = [[]] * M
for i in range(N):
	A[i] = read()
for i in range(M):
	B[i] = read()
C = [[sum(a * b for (a, b) in zip(A_row, B_col)) for A_row in A] for B_col in zip(*B)] 
for i in C:
	print(' '.join(map(str, i)))


import re
def read():
	return list(map(int, re.split(r'\s+', input())))
(N, M, K) = read()
A = [[]] * N
B = [[]] * M
for i in range(N):
	A[i] = read()
for i in range(M):
	B[i] = read()
C = []
for i in range(N):
	C.append([0] * K)
for i in range(N):
	for j in range(K):
		for k in range(M):
			C[i][j] += A[i][k] * B[k][j]
for i in C:
	print(' '.join(map(str, i)))
