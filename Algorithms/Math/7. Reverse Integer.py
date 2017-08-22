class Solution(object):
	def reverse(self, x):
		ans = int(str(x)[::-1]) if(x>=0) else -int(str(-x)[::-1])
		return ans if(ans <= 2 ** 31 - 1 and ans >= - 2 ** 31) else 0
