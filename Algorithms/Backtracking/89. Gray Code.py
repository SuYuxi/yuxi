#formula
class Solution(object):
	def grayCode(self, n):
		L = []
		num = pow(2, n)
		for i in range(num):
			L.append(i ^ (i >> 1))
		return L

#symmetric
#backtrack
class Solution(object):
	def grayCode(self, n):
		def backtrack(n):
			if(n == 0):
				return [0]
			mask = 0x1 << (n-1)
			pre = backtrack(n-1)
			return pre + [mask ^ i for i in pre[::-1]]
	
		return backtrack(n)

#straightforward
class Solution(object):
	def grayCode(self, n):
		count = pow(2, n)
		L = [0]
		num = 0
		for i in range(1, count):
			if(i % 2):
				num ^=0x1
				L.append(num)	
			else:
				mask = 0x1
				while(not (num & mask)):
					mask <<= 1
				mask <<= 1
				num ^= mask
				L.append(num)

		return L
