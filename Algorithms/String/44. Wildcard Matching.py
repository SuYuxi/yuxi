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
