class Solution(object):
	def findRelativeRanks(self, nums):
		sort = sorted(nums)[::-1]
		rank = ["Gold Medal", "Silver Medal", "Bronze Medal"] + map(str, range(4, len(nums) + 1))
		return map(dict(zip(sort, rank)).get, nums)

class Solution(object):
	def findRelativeRanks(self, nums):
		sort = sorted(nums, reverse=True)
		res = list()
		D = dict()
		for inx in range(len(nums)):
			D[sort[inx]] = inx + 1
		for num in nums:
			if(D[num] in [1, 2, 3]):
				res.append(["Gold", "Silver", "Bronze"][D[num]-1] + " Medal")
			else:
				res.append(str(D[num]))
		return res
