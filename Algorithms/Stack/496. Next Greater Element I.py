class Solution(object):
	def nextGreaterElement(self, findNums, nums):
		hashmap = dict()
		stack = list()
		if(nums):
			stack.append(nums[0])
		for num in nums[1:]:
			if(num <= stack[-1]):
				stack.append(num)
			else:
				while(stack and stack[-1] < num):
					hashmap[stack.pop()] = num
				stack.append(num)
		ret = list()
		for num in findNums:
			if(num in hashmap):
				ret.append(hashmap[num])
			else:
				ret.append(-1)
		return ret
