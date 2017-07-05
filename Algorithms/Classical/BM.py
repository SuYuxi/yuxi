#Boyer-Moore
def bmSearch(text, pattern): 
	def _bmGs(pattern, length):
		pos = [length] * (length - 1) + [1]
		inx = length - 1
		inxPre = length - 2
		inxSuff = length - 1
		while(inx >= 0):
			while(inxPre >= 0):
				if(pattern[inxSuff] != pattern[inxPre]):
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
	lenP, lenT = len(pattern), len(text)
	badShift = _bmBc(pattern, lenP)
	goodShift = _bmGs(pattern, lenP)
	inx = 0
	while(inx <= lenT - lenP):
		bias = lenP - 1
		while(bias >= 0 and pattern[bias] == text[inx + bias]):
			bias -= 1
		if(bias < 0):
			return inx
		inx += max(bias - badShift.setdefault(text[inx + bias], -1), goodShift[bias])
	return -1
