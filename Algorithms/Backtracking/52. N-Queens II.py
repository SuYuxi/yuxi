#standard backtracking
class Solution(object):
	def totalNQueens(self, n):
		def backtrack(row):
			if(row == n):
				self.res += 1
				return
			for col in range(n):
				if(emptyCol[col] and emptyDiag[n - 1 + row - col] and emptyReDiag[row + col]):
					emptyCol[col], emptyDiag[n - 1 + row - col], emptyReDiag[row + col] = 0, 0, 0
					backtrack(row + 1)
					emptyCol[col], emptyDiag[n - 1 + row - col], emptyReDiag[row + col] = 1, 1, 1
			return
		emptyCol = [1] * n
		emptyDiag = [1] * (2 * n - 1)
		emptyReDiag = [1] * (2 * n - 1)
		self.res = 0
		backtrack(0)
		return self.res

#slow
class Solution(object):
	def totalNQueens(self, n):
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
				self.count += 1
				return
			for col in range(n):
				pos[row] = col
				if(check(pos, row, col)):
					backtrack(pos, row + 1)
				pos[row] = -1
			return

		self.count = 0
		backtrack([-1] * n, 0)
		return self.count
