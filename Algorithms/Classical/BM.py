#Boyer-Moore
def bmSearch(self, text, pattern): 
	def _good(self, pattern):
		
	def _bad(self, pattern):
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
	tailP = lenP - 1
	subP = tailP
	while(tailP < lenT):
		while(subP >= 0 and patern[lenP - 1 - subP] == text[tailP - 1 - subP]):
			subP -= 1
		if(subP == lenP):
			return subP
		tailP += max(badShift[subP], goodShift[subP])
		subP = 0
	return -1
	
