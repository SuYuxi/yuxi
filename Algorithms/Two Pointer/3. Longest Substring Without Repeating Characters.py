class Solution(object):
	def lengthOfLongestSubstring(self, s):
		length = len(s)
		charset = {}
		maxLength = 0
		start = 0
		for right in range(len(s)):
			char = s[right]
			if(char in charset and charset[char] >= start):
				start = charset[char] + 1	
			else:
				maxLength = max(maxLength, right - start + 1)
			charset[char] = right
		return maxLength
