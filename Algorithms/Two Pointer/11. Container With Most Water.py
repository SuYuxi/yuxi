class Solution(object):
	def maxArea(self, height):
		left = 0
		right = len(height) - 1
		ans = 0
		while(left < right):
			L = right - left
			if(height[left] < height[right]):
				area = height[left] * L
				left += 1
			else:
				area = height[right] * L
				right -= 1
			ans = area if area > ans else ans
		
		return ans
