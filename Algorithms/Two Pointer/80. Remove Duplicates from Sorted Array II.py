class Solution(object):
    def removeDuplicates(self, nums):
		left = 0
		for num in nums:
			if(left < 2 or num > nums[left - 2]):
				nums[left] = num
				left += 1
		return left
