class Solution(object):
	def combinationSum3(self, k, n):
		def backtrack(array, start, k, n):	
			if(k == 0 and n == 0):
				L.append(array)
				return
			if(k > 0 and n > 0):
				for i in range(start, 0, -1):
					backtrack(array + [i], i - 1, k - 1, n - i) 
		L = []
		backtrack([], 9, k, n)
		return L
