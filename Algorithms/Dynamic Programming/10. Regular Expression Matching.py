class Solution(object):
    def isMatch(self, s, p):
		if(p == ''):
			return s == ''
		if(len(p) > 1 and p[1] == '*'):
			return self.isMatch(s, p[2:]) or (s != '' and (s[0] == p[0] or p[0] == '.') and self.isMatch(s[1:], p))
		else:
			return s != '' and (s[0] == p[0] or p[0] == '.') and self.isMatch(s[1:], p[1:])

class Solution(object):
    def isMatch(self, s, p):
		m, n = len(s), len(p)
		state = list()
		for i in range(m+1):
			state += [[False] * n+1]
		state[0][0] = True
		for i in range(m+1):
			for j in range(1,n+1):
				if(p[j - 1] == '*'):
					state[i][j] = state[i][j-2] or (i > 0 and (s[i-1] == p[j-2] or p[j-2] == '.') and state[i-1][j])
				else: 
					state[i][j] = i > 0 and state[i-1][j-1] and (s[i-1] == p[j-1] or p[j-1] == '.')
		return state[m][n]
