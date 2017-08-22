class Solution(object):
	def updateBoard(self, board, click):
		row, col = click
		directions = ((-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1))
		if(0 <= row < len(board) and 0 <= col < len(board[0])):
			if(board[row][col] == 'E'):
				count = sum([board[row + r][col + c] == 'M' for r, c in directions if 0 <= row + r < len(board) and 0 <= col + c < len(board[0])])
				if(count):
					board[row][col] = str(count)
				else:
					board[row][col] = 'B'
					for r, c in directions:
						self.updateBoard(board, (row + r, col + c))
			elif(board[row][col] == 'M'):
				board[row][col] = 'X'
		return board
