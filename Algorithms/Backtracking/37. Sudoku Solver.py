#Fastest
class Cell(object):
	def __init__(self, value = 0):
		self.value = value
		self.possibility = 9
		self.bits = [0] * 9

class Solution(object):
	cells = [[Cell() for _ in range(9)] for _ in range(9)]
	def set(self, row, col, val):
		if
	def constraint(self, row, col, val):
		
    def isValidSudoku(self, board, row, col, val):
		

#Brute-Force Backtracking
class Solution(object):
    def isValidSudoku(self, board, row, col, val):
		r, c = 3 * (row // 3), 3 * (col // 3)
		for inx in range(9):
			if(board[row][inx] == val): return False
			if(board[inx][col] == val): return False
			if(board[r + inx // 3][c + inx % 3] == val): return False
		return True

    def solve(self, board, inx):
		while(inx < 81):
			row = inx // 9
			col = inx % 9
			if(board[row][col] == '.'):
				for val in '123456789':
					if(self.isValidSudoku(board, row, col, val)):
						board[row][col] = val
						if(self.solve(board, inx + 1)):
							return True
						else:
							board[row][col] = '.'
				return False
			inx += 1
		return True

    def solveSudoku(self, board):
		self.solve(board, 0)
