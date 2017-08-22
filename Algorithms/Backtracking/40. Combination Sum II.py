class Solution(object):
    def combinationSum2(self, candidates, target):
		def backtrack(nums, target, start):
			if(not target):
				res.append(nums)
				return
			for inx in range(start, len(candidates)):
				if(inx != start and candidates[inx] == candidates[inx-1]): 
					continue
				if(candidates[inx] <= target):
					backtrack(nums + [candidates[inx]], target - candidates[inx], inx + 1)
				else:
					return
		candidates = sorted(candidates)
		res = list()
		backtrack(list(), target, 0)
		return res
