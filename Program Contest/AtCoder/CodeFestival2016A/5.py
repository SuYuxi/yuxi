#!usr/bin/env python3
#-*- coding: utf-8 -*-
# E-LRU Puzle
def reads(offset = 0):
	return [int(i) - offset for i in input().split(' ')]
def Judge(vector):
	length = len(vector)-1
	for i in range(length):
		if(vector[i] > vector[i+1]):		
			return 0
	return 1
#Data input
(N, M) = reads()
Q = int(input())
A = reads(1)

#Data structure initial
pos = [-1] * M
pat = []
freq = [0] * (M+1)
freq[0] = N
found = set()

#Pattern search & Match count
counter = 0
for i in A[::-1]:
	if (i not in found):
		pat.append(i)
		found.add(i)
		pos[i] = counter
		freq[counter] -= 1
		counter += 1
		freq[counter] += 1
	elif (freq[pos[i]] > 0):
		freq[pos[i]] -= 1
		freq[pos[i]+1] += 1

for i in range(M):
	if (pos[i] == -1):
		pat.append(i)

#Result judge
for i in range(M+1):
	if (freq[i] != 0):
		start = i
		break
print("Yes") if Judge(pat[start:]) else print("No")
