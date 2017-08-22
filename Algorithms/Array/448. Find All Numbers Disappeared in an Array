class Solution(object):
	def findDisappearedNumbers(self, nums):
		for inx in nums:
			index = abs(inx) - 1
			nums[index] = -abs(nums[index])
		ans = []
		for inx in range(len(nums)):
			if(nums[inx] > 0):
				ans.append(inx + 1)
		return ans
