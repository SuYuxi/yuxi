class Solution(object):
	def maxProfit(self, prices):
		free = 0
		cool = 0
		have = float('-inf')
		for p in prices:
			free, have, cool = max(free, cool), max(have, free - p), have + p 
		return max(free, cool)
