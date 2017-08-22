#Boyer-Moore
class Solution(object):
	def strStr(self, haystack, needle):
		def _bmGs(needle, length):
			pos = [length] * (length - 1) + [1]
			inx = length - 1
			inxPre = length - 2
			inxSuff = length - 1
			while(inx >= 0):
				while(inxPre >= 0):
					if(needle[inxSuff] != needle[inxPre]):
						inxSuff = length
					inxSuff -= 1
					inxPre -= 1
					if(inxSuff < inx):
						pos[inx-1] = inxSuff - inxPre
						break
				inx -= 1
			return pos

		def _bmBc(needle, length):
			pos = dict()
			inx = 0
			while(inx < length):
				pos[needle[inx]] = inx
				inx += 1
			return pos

		if(not needle):
			return 0
		lenP, lenT = len(needle), len(haystack)
		badShift = _bmBc(needle, lenP)
		goodShift = _bmGs(needle, lenP)
		inx = 0
		while(inx <= lenT - lenP):
			bias = lenP - 1
			while(bias >= 0 and needle[bias] == haystack[inx + bias]):
				bias -= 1
			if(bias < 0):
				return inx
			inx += max(bias - badShift.setdefault(haystack[inx + bias], -1), goodShift[bias])
		return -1

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
