class Solution(object):
    def minDistance(self, word1, word2):
		len1, len2 = len(word1), len(word2)
		dp = [0] * (len2 + 1)
		temp = [0] * (len2 + 1)
		for i in range(len1): 
			for j in range(len2):
				if(word1[i] == word2[j]):
					temp[j+1] = 1 + dp[j]
				else:
					temp[j+1] = max(temp[j], dp[j+1])
			dp = temp
			temp = [0] * (len2 + 1)
		return len1 + len2 - 2 * dp[len2]
