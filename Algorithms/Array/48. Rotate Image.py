class Solution(object):
    def rotate(self, matrix):
		if(not matrix):
			return matrix
		n = len(matrix) - 1
		for row in range((n + 1) // 2 + (n % 2 != 1)):
			for col in range((n + 1) // 2):
				matrix[row][col], matrix[col][n - row], matrix[n - row][n - col], matrix[n - col][row] = matrix[n - col][row], matrix[row][col], matrix[col][n - row], matrix[n - row][n - col]


class Solution(object):
    def rotate(self, matrix):
		matrix[:] = zip(*matrix[::-1])
		return
