class Solution(object):
	def removeDuplicates(self, nums):
		if(not nums): return 0
		slow = 0
		for fast in range(1, len(nums)): 
			if(nums[slow] != nums[fast]):
				slow += 1
				nums[slow] = nums[fast]
		slow += 1
		nums = nums[:slow]
		return slow
