#permutations
from itertools import permutations
class Solution(object):
	def permuteUnique(self, nums):
		return list(set(permutations(nums, len(nums))))

#backtracking
class Solution(object):
	def permuteUnique(self, nums):
		def backtrack(nums):
			if(len(nums) == 1):
				return [nums]
			L = []
			pre = None
			for inx in range(len(nums)):
				num = nums[inx]
				if(num == pre):
					continue
				else:
					pre = num
				L += [[num] + i for i in backtrack(nums[:inx] +nums[inx+1:])]
			return L
		return backtrack(sorted(nums))
