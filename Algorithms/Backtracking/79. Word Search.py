class Solution(object):
    def exist(self, board, word):
		def backtrack(row, col, inx):
			if(inx == len(word)):
				return True
			if(row < 0 or row == rowL or col < 0 or col == colL or board[row][col] != word[inx]):
				return False
			c = board[row][col]
			board[row][col] = '#'
			res = backtrack(row - 1, col, inx + 1) or backtrack(row + 1, col, inx + 1) or backtrack(row, col + 1, inx + 1) or backtrack(row, col - 1, inx + 1)
			board[row][col] = c
			return res 
			
		if(not board):
			return not word
		rowL, colL = len(board), len(board[0])
		for row in range(rowL):
			for col in range(colL):
				if(backtrack(row, col, 0)):
					return True
		return False
