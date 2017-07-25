class Solution(object):
    def findLongestChain(self, pairs):
		length = len(pairs)
		pairs = sorted(pairs, key = lambda x: x[1])
		res = 0
		curEnd = float('-inf')
		for inx in range(length):
			if(pairs[inx][0] > curEnd):
				curEnd = pairs[inx][1]
				res += 1
		return res
