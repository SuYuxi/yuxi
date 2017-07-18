#Great idea
class Solution(object):
	def isMatch(self, s, p):
		lenS, lenP = len(s), len(p)
		i, j = 0, 0
		match, start = 0, -1
		while(i < lenS):
			if(j < lenP and (s[i] == p[j] or p[j] == '?')):
				i += 1
				j += 1
			elif(j < lenP and p[j] == '*'):
				match = i
				start = j
				j += 1
			elif(start != -1):
				match += 1
				i = match
				j = start + 1
			else:
				return False
				
		while(j < lenP and p[j] == '*'):
			j += 1
		return True if j == lenP else False

#Fantastic idea
class Solution:
	def isMatch(self, s, p):
		length = len(s)
		if len(p) - p.count('*') > length:
			return False
		dp = [True] + [False]*length
		for i in p:
			if i != '*':
				for n in reversed(range(length)):
					dp[n+1] = dp[n] and (i == s[n] or i == '?')
			else:
				for n in range(1, length+1):
					dp[n] = dp[n-1] or dp[n]
			dp[0] = dp[0] and i == '*'
		return dp[-1]
