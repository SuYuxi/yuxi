class Solution(object):
    def fourSumCount(self, A, B, C, D):
		Hash = dict()
		res = 0
		for a in A:
			for b in B:
				Sum = a + b
				Hash[Sum] = Hash.setdefault(Sum, 0) + 1
		for c in C:
			for d in D:
				Sum = -(c + d)
				if(Sum in Hash):
					res += Hash[Sum]
		return res
