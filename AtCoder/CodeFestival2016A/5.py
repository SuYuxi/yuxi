#!usr/bin/env python3
#-*- coding: utf-8 -*-
# E-LRU Puzle
def reads(offset = 0):
	return [int(i) - offset for i in input().split(' ')]
#Data input
(N, M) = reads()
Q = int(input())
A = reads(1)

#Data structure initial
pos = [-1] * M
pat = []
freq = [0] * (M+1)
freq[0] = N

#Pattern search & Match count
counter = 0
for i in A[::-1]:
	if (i not in pat):
		pat.append(i)
		pos[i] = counter
		freq[counter] -= 1
		counter += 1
		freq[counter] += 1
	else:
		temp = pos[i]
		if (freq[temp] > 0):
			freq[temp] -= 1
			freq[temp+1] += 1

if(counter != M):
	for i in range(M):
		if (i not in pat):
			pat.append(i)

#Result judge
for i in range(M):
	if (freq[i] != 0):
		start = i
		break

p = pat[start:]
p.sort()
if(p == pat[start:]):
	print("Yes")
else:
	print("No")
