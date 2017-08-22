class Solution(object):
	def countAndSay(self, n):
		if(n == 0): return ''
		ret = '1'
		n -= 1
		while(n):
			cur = ''
			length = len(ret)
			inx = 0
			while(inx < length):
				count = 1
				while(inx + 1 < length and ret[inx] == ret[inx+1]):
					count += 1
					inx += 1
				cur += str(count) + ret[inx]
				inx += 1
			ret = cur
			n -= 1
		return ret
