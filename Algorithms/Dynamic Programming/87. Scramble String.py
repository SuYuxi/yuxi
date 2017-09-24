class Solution(object):
	def __init__(self):
		self.dp = dict()
	def isScramble(self, s1, s2):
		if((s1, s2) in self.dp):
			return self.dp[(s1, s2)]
		if((s2, s1) in self.dp):
			return self.dp[(s2, s1)]
		if(s1 == s2):
			self.dp[(s1, s2)] = True
			return True
		count = dict()
		length = len(s1)
		for inx in range(length):
			count[s1[inx]] = count.setdefault(s1[inx], 0) + 1
			count[s2[inx]] = count.setdefault(s2[inx], 0) - 1
		for cnt in count.values():
			if(cnt): 
				self.dp[(s1, s2)] = False
				return False
		for i in range(1, length): 
			if(self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:])):
				return True
			if(self.isScramble(s1[:i], s2[length - i:]) and self.isScramble(s1[i:], s2[:length - i])):
				return True
		self.dp[(s1, s2)] = False
		return False
