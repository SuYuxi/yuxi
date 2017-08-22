class Solution(object):
    def optimalDivision(self, nums):
		length = len(nums)
		if(length == 1):
			return str(nums[0])
		if(length == 2):
			return str(nums[0]) + '/' + str(nums[1])
		res = str(nums[0]) + '/(' + str(nums[1])
		inx = 2
		while(inx < length):
			res += '/' + str(nums[inx]) 
			inx += 1
		res += ')'
		return res
