from collections import defaultdict
class Solution(object):
	def topKFrequent(self, nums, k):
		d = defaultdict(int)
		for i in nums:
			d[i] += 1
		return sorted(d, key = lambda x: d[x] , reverse = True)[:k]
