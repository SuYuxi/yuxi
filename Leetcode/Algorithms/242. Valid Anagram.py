class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        d = dict()
        for i in range(len(s)):
            d[s[i]] = d.setdefault(s[i],0) + 1
            d[t[i]] = d.setdefault(t[i],0) - 1
        for j in d:
            if d[j] != 0:
                return False
        return True

class Solution(object):
	def isAnagram(self, s,t):
		s = list(s)
		t = list(t)
		s.sort()
		t.sort()
		return s == t
