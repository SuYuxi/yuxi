#Boyer-Moore
def bmSearch(self, text, pattern): 
	def _bmGs(self, pattern):
		
	def _bmBc(self, pattern):
		length = len(pattern)
		pos = dict()
		inx = 0
		while(inx < length):
			pos[pattern[inx]] = inx	
			inx += 1
		return pos
	lenP, lenT = len(pattern), len(text)
	suff = 	
	badShift = 
	goodShift = 
	tailT = lenP - 1
	inxT = tailT
	inxP = lenP - 1
	while(tailT < lenT):
		while(inxP >= 0 and patern[inxP] == text[inxT]):
			inxP -= 1
			inxT -= 1
		if(inxP < 0):
			return inxT + 1
		tailP += max(badShift[inxP], goodShift[inxP])
		inxP = 0
	return -1
	
