class Solution(object):
	def wordPattern(self, pattern, str):
		words = str.split()
		if(len(pattern) != len(words)):
			return False
		inx = 0
		D = dict()
		P = dict()
		while(inx < len(pattern)):
			if(D.setdefault(words[inx], inx) != P.setdefault(pattern[inx], inx)):
				return False
			inx += 1
		return True
