from collections import defaultdict
def factorial(n):
	p = 1
	for i in range(1,n+1):
		p *= i
	return p
def Anm(n, m):
	return int(factorial(n) / factorial(n - m))
def Cnm(n, m):
	return int((factorial(n) / factorial(m)) / factorial(n - m))
	
s = input()
length = len(s)
index = defaultdict(int)
if(length > 10):
	for i in range(11,length):
		if(s[i%10] != s[i]):
			print(0) 
			exit()
else:
	temp = defaultdict(int)
	for i in s:
		temp[i] += 1
		if(i != '?' and temp[i] > 1):
			print(0)
			exit()
for i in range(length):
	if(s[i] != '?'):
		index[i%10] += 1	
	else:
		index[i%10] += 0
qmarknum = 0
digitnum = 0
for i in index: 
	if(index[i] == 0):
		qmarknum += 1
	else:
		digitnum += 1
print(Anm(10-digitnum, qmarknum))
#print(Cnm(10-digitnum, qmarknum))
