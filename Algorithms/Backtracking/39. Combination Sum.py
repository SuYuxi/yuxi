#backtrack
class Solution(object):
	def combinationSum(self, candidates, target):
		def backtrack(pre, target, left):
			for inx in range(left, length):
				num = candidates[inx]
				temp = target - num
				if(not temp):
					L.append(pre + [num])
					return
				if(temp < 0):
					return
				backtrack(pre + [num], temp, inx)
			return
				
		L = []
		candidates.sort()
		length = len(candidates)
		backtrack([], target, 0)
		return L
