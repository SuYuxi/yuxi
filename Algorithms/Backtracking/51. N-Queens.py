#standard backtracking
class Solution(object):
    def solveNQueens(self, n):
		def backtrack(row):
			if(row == n):
				res.append([''.join(board[i]) for i in range(n)])
				return
			for col in range(n):
				if(emptyCol[col] and emptyDiag[n - 1 + row - col] and emptyReDiag[row + col]):
					board[row][col] = 'Q'
					emptyCol[col], emptyDiag[n - 1 + row - col], emptyReDiag[row + col] = 0, 0, 0
					backtrack(row + 1)
					emptyCol[col], emptyDiag[n - 1 + row - col], emptyReDiag[row + col] = 1, 1, 1
					board[row][col] = '.'
			return
		emptyCol = [1] * n
		emptyDiag = [1] * (2 * n - 1)
		emptyReDiag = [1] * (2 * n - 1)
		res = []
		board = [['.'] * n for _ in range(n)]
		backtrack(0)
		return res
#slow		
class Solution(object):
    def solveNQueens(self, n):
		def check(pos, row, col):
			i = 0
			while(i < row):
				j = pos[i]
				if(j == col or row - i == abs(col - j)):
					return False
				i += 1
			return True
			
		def backtrack(pos, row):
			if(row == n):
				self.board.append(['.' * i + 'Q' + '.' * (n - i - 1) for i in pos])
				return
			for col in range(n):
				pos[row] = col
				if(check(pos, row, col)):
					backtrack(pos, row + 1)
				pos[row] = -1
			return

		self.board = list()
		backtrack([-1] * n, 0)
		return self.board
