class Solution(object):
    def searchMatrix(self, matrix, target):
		if(not matrix):
			return False
		rowLen, colLen = len(matrix), len(matrix[0])
		left, right = 0, rowLen * colLen - 1
		while(left <= right):
			mid = (left + right) >> 1
			row, col = mid // colLen, mid % colLen
			num = matrix[row][col]
			if(num < target):
				left = mid + 1
			elif(num > target):
				right = mid - 1
			else:
				return True
		return False
