class Solution(object):
    def imageSmoother(self, M):
		if(not M or not M[0]):
			return M
		rowL, colL = len(M), len(M[0])	
		res = [[0] * colL for _ in range(rowL)]
		for row in range(rowL):
			for col in range(colL):
				Sum = 0
				rL, rH = max(0, row-1), min(row+2, rowL)
				cL, cH = max(0, col-1), min(col+2, colL)
				for r in range(rL, rH):
					Sum += sum(M[r][cL:cH])
				res[row][col] = Sum // ((rH - rL) * (cH - cL))
		return res
