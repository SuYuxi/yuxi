def read():
	return [int(i) for i in input().split(' ')]
N, T = read()
A = read()
t_min = A[0]
cost = 1
profit = 0

for p in A:
	if(p < t_min):
		t_min = p
	elif(p - t_min == profit):
		cost += 1
	elif(p - t_min > profit):
		cost = 1
		profit = p - t_min
print(cost)
