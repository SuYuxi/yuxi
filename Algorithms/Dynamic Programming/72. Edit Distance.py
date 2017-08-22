class Solution(object):
    def minDistance(self, word1, word2):
		len1, len2 = len(word1), len(word2)
		dp = [inx for inx in range(len2+1)]
		for i in range(1, len1+1):
			digonal = dp[0]
			dp[0] = i
			for j in range(1, len2+1):
				temp = dp[j]
				if(word1[i-1] == word2[j-1]):
					dp[j] = digonal
				else:
					dp[j] = 1 + min(dp[j], dp[j-1], digonal)
				digonal = temp 
		return dp[-1]
