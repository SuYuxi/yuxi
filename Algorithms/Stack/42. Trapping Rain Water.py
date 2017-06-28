#2pointer
class Solution(object):
    def trap(self, height):
		left = 0
		right = len(height) - 1
		leftMax = float('-inf')
		rightMax = float('-inf')
		volume = 0
		while(left < right):
			if(height[left] < height[right]):
				if(height[left] >= leftMax):
					leftMax = height[left]
				else:
					volume += leftMax - height[left]
				left += 1
			else:
				if(height[right] >= rightMax):
					rightMax = height[right]
				else:
					volume += rightMax - height[right]
				right -= 1
		return volume

#stack
class Solution(object):
    def trap(self, height):
		stack = list()
		volume = 0	
		inx = 0
		while(inx < len(height)):
			if(not stack or height[inx] <= height[stack[-1]]):
				stack.append(inx)
				inx += 1
			else:
				pit = height[stack.pop()]
				if(stack):
					volume += (inx - stack[-1] - 1) * (min(height[inx], height[stack[-1]]) - pit)
		return volume
#2round
class Solution(object):
    def trap(self, height):
		if(not height):
			return 0
		l = len(height)
		leftMax = [None] * l
		rightMax = [None] * l
		leftMax[0] = height[0]
		rightMax[-1] = height[-1]
		for inx in range(1, len(height)):
			leftMax[inx] = max(height[inx], leftMax[inx - 1])
			rightMax[-inx-1] = max(height[-inx-1], rightMax[-inx])
		volume = 0
		for inx in range(len(height)):
			volume += min(leftMax[inx], rightMax[inx]) - height[inx]
		return volume 
