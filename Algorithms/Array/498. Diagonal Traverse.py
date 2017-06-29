class Solution(object):
    def findDiagonalOrder(self, matrix):
		if(not matrix):
			return []
		rLen, cLen = len(matrix), len(matrix[0])
		D = [[] for _ in range(rLen + cLen - 1)]
		row, col = 0, 0
		while(row < rLen):
			while(col < cLen):
				inx = col + row
				D[inx].append(matrix[row][col])
				col += 1
			row += 1
			col = 0
		inx = 0
		res = list()
		while(inx < rLen + cLen - 1):
			res += D[inx] if inx % 2 else D[inx][::-1]
			inx += 1
		return res

class Solution(object):
    def findDiagonalOrder(self, matrix):
		if(not matrix):
			return []
		rLen, cLen = len(matrix), len(matrix[0])
		res = [None for _ in range(rLen * cLen)]
		row, col = 0, 0
		direction = [(-1, 1), (1, -1)]
		d = 0
		for inx in range(rLen * cLen): 
			res[inx] = matrix[row][col]
			row += direction[d][0]
			col += direction[d][1]
			if(col >= cLen):
				col = cLen - 1
				row += 2
				d = 1
			elif(row < 0):
				row += 1
				d = 1
			elif(row >= rLen):
				row -= 1
				col += 2
				d = 0
			elif(col < 0):
				col += 1
				d = 0
		return res
