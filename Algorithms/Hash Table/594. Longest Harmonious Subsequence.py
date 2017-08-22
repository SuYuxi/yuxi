class Solution(object):
    def findLHS(self, nums):
		D = dict()
		res = 0
		for num in nums:
			D[num] = D.setdefault(num, 0) + 1
		for key in D:
			if(key + 1 in D):
				res = max(res, D[key] + D[key+1])
		return res
