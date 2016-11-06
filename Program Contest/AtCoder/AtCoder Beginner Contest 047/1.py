def read():
	return [int(i) for i in input().split(' ')]
L = read()
if(L[0] + L[1] == L[2] or L[0] + L[2] == L[1] or L[1] + L[2] == L[0]):
	print('Yes')
else:
	print('No')
