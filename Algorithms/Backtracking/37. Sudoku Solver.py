#Constraint Backtracking
class Cell(object):
	def __init__(self, value = 0):
		self.value = value
		self.possibility = 9
		self.bits = [0] * 10
	
	def copy(self):
		cell = Cell(self.value)
		cell.possibility = self.possibility
		cell.bits = self.bits[:]
		return cell

class Solution(object):
	def __init__(self):
		self.cells = [[Cell() for col in range(9)] for row in range(9)]

	def set(self, row, col, val):
		cell = self.cells[row][col]
		if(cell.value == val):
			return True
		if(cell.bits[val]):
			return False
		cell.value = val
		cell.bits = [1] * 10
		cell.bits[val] = 0
		cell.possibility = 1
		r = (row // 3) * 3
		l = (col // 3) * 3
		for inx in range(9):
			if(inx != col and not self.constraint(row, inx, val)):
				return False
			if(inx != row and not self.constraint(inx, col, val)):
				return False
			if(r + (inx // 3) != row and l + (inx % 3) != col and not self.constraint(r + (inx // 3), l + (inx % 3) , val)):
				return False
		return True

	def constraint(self, row, col, val):
		cell = self.cells[row][col]
		if(cell.value == val):
			return False
		if(cell.bits[val]):
			return True
		cell.possibility -= 1
		cell.bits[val] = 1
		if(cell.possibility == 1):
			for bit in range(1, 10):
				if(not cell.bits[bit]):
					return self.set(row, col, bit)
		return True

	def findEmptyValue(self):
		backtrackQueue = list()
		for row in range(9):
			for col in range(9):
				cell = self.cells[row][col]
				if(not cell.value):
					backtrackQueue.append((row, col, cell.possibility))
		return sorted(backtrackQueue, key=lambda x: x[2])

	def snapshot(self):
		return [[self.cells[row][col].copy() for col in range(9)] for row in range(9)]

	def backtracking(self, empty, inx):
		if(inx >= len(empty)):
			return True
		row = empty[inx][0]
		col = empty[inx][1]
		cell = self.cells[row][col]
		if(cell.value):
			return self.backtracking(empty, inx + 1)
		bits = cell.bits[:]
		backup = self.snapshot()
		for val in range(1, 10):
			if(not bits[val]):
				if(self.set(row, col, val)):
					if(self.backtracking(empty, inx + 1)):
						return True
				self.cells = backup
		return False

	def solveSudoku(self, board):
		for row in range(9):
			for col in range(9):
				value = board[row][col]
				if(value != '.' and not self.set(row, col, int(value))):
					return
		empty = self.findEmptyValue()
		self.backtracking(empty, 0)
		for row in range(9):
			tempRow = ''
			for col in range(9):
				tempRow += str(self.cells[row][col].value)
			board[row] = tempRow

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
