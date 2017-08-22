class Solution(object):
    def firstMissingPositive(self, nums):
		length = len(nums)
		for inx in range(length): 
			while(nums[inx] > 0 and nums[inx] <= length and nums[nums[inx]-1] != nums[inx]):
				nums[nums[inx]-1], nums[inx] = nums[inx], nums[nums[inx]-1] 
		for inx in range(length): 
			if(nums[inx] -1 != inx):
				return inx + 1
		return length + 1
