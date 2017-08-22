class Solution(object):
    def isNumber(self, s):
		pattern = re.compile(r'^ *[+-]?(\d+\.?\d*|\.\d+)(e[+-]?\d+)? *$')
		return re.match(pattern, s) != None

class Solution(object):
    def isNumber(self, s):
		s = s.strip()
		numberSeen = False
		pointSeen = False
		eSeen = False
		numberAfterE = True
		for inx in range(len(s)):
			c = s[inx]
			if('0' <= c <= '9'):
				numberSeen = True
				numberAfterE = True
			elif(c == '.'):
				if(pointSeen or eSeen):
					return False
				pointSeen = True
			elif(c == 'e'):
				if(eSeen or not numberSeen):
					return False
				eSeen = True
				numberAfterE = False
			elif(c == '+' or c == '-'):
				if(inx != 0 and s[inx-1] != 'e'):
					return False
			else:
				return False
		return numberSeen and numberAfterE

