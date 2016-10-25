class Solution(object):
	def countBattleships(self, board):
		ans = 0
		rowL = len(board)
		colL = len(board[0])
		for i in range(rowL): 
			for j in range(colL):
				if(board[i][j] == "X" and (i == 0 or board[i-1][j] != "X") and (j == 0 or board[i][j-1] != "X")):
					ans += 1
		return ans
