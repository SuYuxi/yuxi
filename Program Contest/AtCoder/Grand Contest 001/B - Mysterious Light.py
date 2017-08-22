def read():
	return [int(i) for i in input().split(" ")]

def calculate(x, y):
	if(y % x == 0):
		return x * (2 * (y / x) - 1) 
	else:
		return x * 2 * (y // x) + calculate(y % x, x) 
(N, X) = read()
length = N + calculate(X, N - X)
print(int(length))
