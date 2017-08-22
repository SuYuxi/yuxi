class Solution(object):
    def isValidSudoku(self, board):
		D = set()
		for inxR, row in enumerate(board):
			for inxL, num in enumerate(row):
				if(num != '.'):
					if('{}({})'.format(inxL, num) in D or '({}){}'.format(num, inxR) in D or '{}({}){}'.format(inxL // 3, num, inxR // 3) in D):
						return False
					D.add('{}({})'.format(inxL, num))
					D.add('{}({}){}'.format(inxL // 3, num, inxR // 3))
					D.add('({}){}'.format(num, inxR))
		return True

class Solution(object):
    def isValidSudoku(self, board):
		D = set()
		for inxR, row in enumerate(board):
			for inxL, num in enumerate(row):
				if(num != '.'):
					if((inxL, num) in D or (num, inxR) in D or (inxL // 3, num, inxR // 3) in D):
						return False
					D.add((inxL, num))
					D.add((inxL // 3, num, inxR // 3))
					D.add((num, inxR))
		return True
