#hashmap
class Solution(object):
	def singleNumber(self, nums):
		D = dict()
		for i in nums:
			D[i] = D.setdefault(i, 0) + 1
		for i in D:
			if(D[i] == 1):
				return i

#bit manipulation
#00 > 10 > 01 > 00
class Solution(object):
	def singleNumber(self, nums):	
		ones, twos = 0, 0
		for i in nums:
			ones = (ones ^ i) & ~twos
			twos = (twos ^ i) & ~ones
		return ones
