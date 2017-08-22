def read():
	return [int(i) for i in input().split(' ')]
W, H, N = read()
x = [0] * N
y = [0] * N
a = [0] * N
for i in range(N):
	x[i], y[i], a[i] = read()
new_x = [0] + x + [W]
new_y = [0] + y + [H]
for inx in range(N):
	if(a[inx] == 1):
		new_x = [num for num in new_x if num >= x[inx]] 
	elif(a[inx] == 2):
		new_x = [num for num in new_x if num <= x[inx]] 
	elif(a[inx] == 3):
		new_y = [num for num in new_y if num >= y[inx]] 
	else:
		new_y = [num for num in new_y if num <= y[inx]] 
if(not(new_x) or not(new_y)):
	print(0)
	exit()
area = (max(new_x) - min(new_x)) * (max(new_y) - min(new_y))
print(area)
