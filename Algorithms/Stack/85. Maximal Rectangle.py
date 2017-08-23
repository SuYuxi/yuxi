class Solution(object):
    def maximalRectangle(self, matrix):
		if(not matrix):
			return 0
		length = len(matrix[0])
		height = [0] * (length + 1)
		res = 0
		for row in matrix:
			for inx in range(length):
				height[inx] = height[inx] + 1 if row[inx] == '1' else 0
			stack = [-1]
			for inx in range(length + 1):
				while(height[inx] < height[stack[-1]]):
					top = height[stack.pop()]
					res = max(res, top * (inx - stack[-1] - 1))
				stack.append(inx)
		return res
