class Solution(object):
    def setZeroes(self, matrix):
		if(not matrix):
			return matrix
		lenRow = len(matrix)
		lenCol = len(matrix[0])
		col0 = 0
		for row in range(lenRow):
			if(not matrix[row][0]):
				col0 = 1
			for col in range(1, lenCol):
				if(not matrix[row][col]):
					matrix[row][0], matrix[0][col] = 0, 0
		for row in reversed(range(lenRow)):
			for col in reversed(range(1, lenCol)):
				if(not matrix[row][0] or not matrix[0][col]):
					matrix[row][col] = 0
			if(col0):
				matrix[row][0] = 0
		return
