class Solution(object):
	def numDecodings(self, s):
		if(not s):
			return 0
		n = len(s)
		dp = [0] * (n + 1)
		dp[0] = 1
		dp[1] = 1 if s[0] != '0' else 0
		for inx in range(1, n):
			if(s[inx] != '0'):
				dp[inx + 1] += dp[inx] 
			if(s[inx-1] == '1' or (s[inx-1] == '2' and s[inx] in '0123456')):
				dp[inx+1] += dp[inx-1]
		return dp[-1]
