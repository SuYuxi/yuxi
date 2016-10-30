class Solution(object):
	def totalNQueens(self, n):
		def check(Pos, col):
			row = len(Pos)
			for i,j in enumerate(Pos):
				if(j == col or row - i == abs(col - j)):
					return False
			return True
			
		def BackTrack(Pos, row):
			for col in range(n):
				if(check(Pos, col)):
					if(len(Pos) == n - 1):
						self.count += 1
						continue
					Pos.append(col)
					BackTrack(Pos, row + 1)
					Pos.pop()
			return

		self.count = 0
		Pos = []
		BackTrack(Pos, 0)
		return self.count
