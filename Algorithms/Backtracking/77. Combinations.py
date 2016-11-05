#combinations
from itertools import combinations
class Solution(object):
	def combine(self, n, k):
		return list(combinations(list(range(1, n+1)), k))

#backtrack
#super fast!
class Solution(object):
	def combine(self, n, k):
		def backtrack(pre, k, left):
			if(not k):
				L.append(pre)
				return
			for inx in range(left, length - k + 1):
				backtrack(pre + [nums[inx]], k - 1, inx + 1)
			return
				
		nums = list(range(1, n+1))
		length = len(nums)
		L = []
		backtrack([], k, 0)
		return L
