class Solution:
	def maxCount(self, m, n, ops):
		minR, minC = m, n 
		for op in ops:
			minR = min(minR, op[0])
			minC = min(minC, op[1])
		return minR * minC 
