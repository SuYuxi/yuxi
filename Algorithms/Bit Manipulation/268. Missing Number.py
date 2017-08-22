import operator
class Solution(object):
	def missingNumber(self, nums):
		l = len(nums)
		return l * (l + 1) / 2 - sum(nums)

class Solution(object):
	def missingNumber(self, nums):
		l = len(nums)
		return reduce(operator.xor, nums + range(l + 1))

class Solution(object):
	def missingNumber(self, nums):
		l = len(nums)
		return reduce(operator.xor, nums) ^ [0, l, 1, l+1][(l+1) % 4]
