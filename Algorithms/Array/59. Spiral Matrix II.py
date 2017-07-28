class Solution(object):
    def generateMatrix(self, n):
		res = [[None] * n for _ in range(n)]
		dirRow, dirCol = 0, 1
		row, col = 0, 0
		for val in range(1, n ** 2 + 1):
			res[row][col] = val
			if(res[(row + dirRow) % n][(col + dirCol) % n]):
				dirRow, dirCol = dirCol, -dirRow
			row += dirRow
			col += dirCol
		return res

class Solution(object):
    def generateMatrix(self, n):
		length = n ** 2 
		directions = ((0, 1), (1, 0), (0, -1), (-1, 0))
		inxDir, inxCnt = 0, 0
		count =[n, n-1]
		row, col = 0, -1
		inx = 1
		res = [[None] * n for _ in range(n)]
		while(count[inxCnt]):
			direction = directions[inxDir]
			for _ in range(count[inxCnt]):
				row += direction[0]
				col += direction[1]
				res[row][col] = inx
				inx += 1
			count[inxCnt] -= 1
			inxDir = (inxDir + 1) % 4
			inxCnt = inxDir % 2
		return res
