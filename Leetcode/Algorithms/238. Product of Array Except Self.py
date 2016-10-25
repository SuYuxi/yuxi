class Solution(object):
	def productExceptSelf(self, nums):
		p = 1
		output = []
		for i in nums:
			output.append(p) 
			p *= i
		p = 1
		for i in range(len(nums)-1, -1, -1):
			output[i] = output[i] * p
			p *= nums[i]
		return output
