#kmp 
class Solution(object):
	def strStr(self, haystack, needle):
		def kmpNext(needle):
			next = list()
			for L in range(len(needle)):
				left = needle[:L]
				right = needle[-L:]
				longest = 0
				if(left == right):
					next.append(L)
					longest = L
				else:
					next.append(longest)
			return next

		if(not haystack and not needle):
			return 0
		next = kmpNext(needle)
		lenNeedle = len(needle)
		lenHay = len(haystack)
		i, j = 0, 0 
		while(i <= lenHay - lenNeedle):
			while(j < lenNeedle):
				if(haystack[i+j] == needle[j]):
					j += 1
				else:
					i += ((j - next[j]) or 1)
					j = next[j]
					break
			if(j == lenNeedle):
				return i
		return -1 
