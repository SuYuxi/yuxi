#kmp 
class Solution(object):
	def strStr(self, haystack, needle):
		def kmpInit(needle):
			length = len(needle)
			kmpList = [0] * length
			left, right = 0, 1
			while(right < length):
				if(needle[left] == needle[right]):
					left += 1
					kmpList[right] = left
					right += 1
				else:
					if(left != 0):
						left = kmpList[left-1]
					else:
						kmpList[right] = 0
						right += 1
			return kmpList

		if(not needle): return 0
		kmpList = kmpInit(needle)
		lenNeedle = len(needle)
		lenHay = len(haystack)
		i, j = 0, 0
		while(i < lenHay):
			if(haystack[i] == needle[j]):
				i += 1
				j += 1
				if(j == lenNeedle):
					return i - j
			else:
				if(j != 0):
					j = kmpList[j-1]
				else:
					i += 1
		return -1
