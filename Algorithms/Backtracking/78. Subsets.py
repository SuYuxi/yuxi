class Solution(object):
    def subsets(self, nums):
		def backtrack(tempList, start):
			res.append(tempList)
			for inx in range(start, len(nums)):
				backtrack(tempList + [nums[inx]], inx + 1)
		res = list()
		backtrack(list(), 0)
		return res

class Solution(object):
    def subsets(self, nums):
		length = len(nums)
		size = 2 ** length
		res = [[] for _ in range(size)]
		for i in range(size):
			for j in range(length):
				if((i >> j) & 1):
					res[i].append(nums[j])
		return res

class Solution(object):
    def subsets(self, nums):
		return reduce(lambda x, y:[z + [y] for z in x] + x, nums, [[]])
