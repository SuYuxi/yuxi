#permutation
from itertools import permutations
class Solution(object):
	def permute(self, nums):
		return list(permutations(nums, len(nums))) 

#backtrack top-bottom
class Solution(object):
	def permute(self, nums):
		def backtrack(pre):
			if(len(pre) == length):
				L.append(pre)
				return
			for num in nums:
				if(num in pre):
					continue
				backtrack(pre + [num])
		L = []
		length = len(nums)
		backtrack([])
		return L

#backtrack bottom-top
class Solution(object):
	def permute(self, nums):
		def backtrack(nums):
			if(len(nums) == 1):
				return [nums]

			L = []
			for inx in range(len(nums)):
				L += [[nums[inx]] + i for i in backtrack(nums[:inx] + nums[inx+1:])]
			return L
		return backtrack(nums)
