class Solution(object):
    def checkRecord(self, s):
		L, A = 0, 0
		for state in s:
			if(state != 'L'):
				L = 0
				if(state == 'A'):
					A += 1
					if(A > 1):
						return False
			else:
				L += 1
				if(L > 2):
					return False
		return True
