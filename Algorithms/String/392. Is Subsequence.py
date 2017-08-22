class Solution(object):
	def isSubsequence(self, s, t):
		iters, itert = iter(s), iter(t)
		temps = tempt = 0
		while True:
			if(temps == tempt):
				try:
					temps = next(iters) 
				except StopIteration:
					return True
			try:
				tempt = next(itert)
			except StopIteration:
				return False

class Solution(object):
	def isSubsequence(self, s, t):
		t = iter(t)			
		return all(c in t for c in s)

class Solution(object):
	def isSubsequence(self, s, t):
		start = 0
		for i in s:
			start = t.find(i, start)
			if(start == -1):
				return False
		start += 1
		return True
