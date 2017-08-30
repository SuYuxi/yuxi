class Solution(object):
    def nextGreaterElements(self, nums):
		length = len(nums)
		res = [-1] * length
		stack = list()
		for inx in range(length * 2):
			num = nums[inx % length]
			while(stack and num > nums[stack[-1]]):
				res[stack.pop()] = num
			if(inx < length):
				stack.append(inx)
		return res
