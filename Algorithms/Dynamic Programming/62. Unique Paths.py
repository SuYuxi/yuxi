#dynamic programming with hashmap top-bottom
class Solution(object):
	def uniquePaths(self, m, n):
		def dp(m, n):
			if((m, n) in hashmap):
				return hashmap[(m, n)]
			else:
				right = dp(m-1, n) if m > 1 else 0
				down = dp(m, n - 1) if n > 1 else 0
				count = right + down
				hashmap[(m, n)] = count 
				return count
		if(m < 0 or n < 0):
			return 0
		else:
			hashmap = {(1, 1): 1}
			return dp(m, n)

#dynamic programming bottom-top
class Solution(object):
	def uniquePaths(self, m, n):
		if(m > n):
			m, n = n, m
		if(m < 1):
			return 0
		p_row = [1] * n
		cur = [0] * n
		for row in range(1, m): #symmetric metrix
			cur[row-1] = p_row[row]
			for col in range(row, n):
				cur[col] = p_row[col] + cur[col - 1]
			p_row = cur
		return cur[n - 1] if m > 1 else 1

		
#combination formula
class Solution(object):
	def uniquePaths(self, m, n):
		N = m + n - 2
		K = min(m, n) - 1
		ans = 1
		for i in range(1, K + 1):
			ans = ans * (N - K + i) / i
		return ans
