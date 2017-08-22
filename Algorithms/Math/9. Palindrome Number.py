class Solution(object):
	def isPalindrome(self, x):
		if(x < 0): return False
		p = x
		q = 0
		while(p):
			q = q * 10 + p % 10
			p //= 10
		return q == x
