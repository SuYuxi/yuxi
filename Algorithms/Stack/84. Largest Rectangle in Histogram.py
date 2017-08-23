#best
class Solution(object):
    def largestRectangleArea(self, heights):
		length = len(heights)
		heights.append(0)
		stack = [-1]
		res = 0
		for inx in range(length + 1):
			while(heights[inx] < heights[stack[-1]]):
				top = stack.pop()
				res = max(res, heights[top] * (inx - stack[-1] - 1))
			stack.append(inx)
		return res

#slower
class Solution(object):
    def largestRectangleArea(self, heights):
		length = len(heights)
		stack = list()
		res = 0
		inx = 0
		while(inx <= length):
			height = heights[inx] if inx != length else 0
			if(stack and height < heights[stack[-1]]):
				top = stack.pop()
				left = stack[-1] if stack else -1
				res = max(res, heights[top] * (inx - left - 1))
			else:
				stack.append(inx)
				inx += 1
		return res
