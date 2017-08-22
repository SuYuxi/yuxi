class Solution(object):
	def reverseStr(self, s, k):
		res = str()
		for inx in range(0, len(s), 2*k):
			res += s[inx:inx+k][::-1]
			res += s[inx+k:inx+2*k]
		return res
