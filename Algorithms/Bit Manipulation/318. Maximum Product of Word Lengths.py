class Solution(object):
	def maxProduct(self, words):
		d = dict()
		for w in words:
			mask = 0x0
			for c in w:
				mask |= 0x1 << (ord(c) - 97)
			d[mask] = max(d.get(mask, 0), len(w))
		return max([d[i] * d[j] for i in d for j in d if not (i & j)] or [0])

class Solution(object):
	def maxProduct(self, words):
		d = dict()
		for w in words:
			mask = 0x0
			for c in w:
				mask |= 0x1 << (ord(c) - 97)
			d[mask] = max(d.get(mask, 0), len(w))
		l = len(d)
		ans = 0
		for i in range(l):
			ref = d.popitem()
			for j in d:
				if(not (ref[0] & j)):
					ans = max(ans, ref[1] * d[j])
		return ans
		return max([d[i] * d[j] for i in d for j in d if not (i & j)] or [0])
