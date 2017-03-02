class Solution(object):
	def longestPalindrome(self, s):
		def longestCenter(inx1, inx2):
			L, R = inx1, inx2
			while(L >= 0 and R < length and s[L] == s[R]):
				L -= 1
				R += 1
			return R - L - 1
			
		start, end = 0, 0
		length = len(s)
		for inx in range(length):
			l1= longestCenter(inx, inx)
			l2= longestCenter(inx, inx+1)
			maxl = max(l1, l2) 
			if(maxl > end - start):
				start = inx - ((maxl - 1) // 2)
				end = inx + ((maxl) // 2) + 1
		return s[start:end]

class Solution(object):
	def longestPalindrome(self, s):
		expand = '#'
		for c in s:
			expand += c + '#'
		length = len(expand)
		P = [0] * length
		center = 0
		border = 0
		pos = 0
		maxL = (0, 0)
		while(pos < length):
			if(border - pos > P[2*center - pos]):
				P[pos] = P[2*center - pos]
			else:
				bias = border - pos 
				while((pos + bias) < length and (pos - bias) >= 0 and expand[pos + bias] == expand[pos - bias]):
					bias += 1
				P[pos] = bias 
				center = pos
				border = pos + bias 
				if(bias > maxL[0]):
					maxL = (bias, pos) 
			pos += 1 
		return expand[maxL[1]-maxL[0]+1:maxL[1]+maxL[0]].replace('#','')
		#return s[(maxL[1] - maxL[0] + 1)//2:(maxL[1] - maxL[0] + 1)//2 + maxL[0] - 1]
