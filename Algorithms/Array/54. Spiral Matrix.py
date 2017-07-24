class Solution(object):
    def spiralOrder(self, matrix):
		if(not matrix):
			return list()
		lenR, lenC = len(matrix), len(matrix[0])
		directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
		count = [lenC, lenR - 1]
		nDir, nCnt = 0, 0
		row, col = 0, -1
		res = list()
		while(count[nCnt]):
			direct = directions[nDir]
			for _ in range(count[nCnt]):
				row += direct[0]
				col += direct[1]
				res.append(matrix[row][col])
			count[nCnt] -= 1
			nDir = (nDir + 1) % 4
			nCnt = nDir % 2
		return res
