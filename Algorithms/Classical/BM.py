#Boyer-Moore
def bmSearch(self, text, pattern): 
	def _goodStr(self, pattern):
	def _badStr(self, pattern):
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
	
