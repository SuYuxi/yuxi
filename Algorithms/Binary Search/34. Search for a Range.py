class Solution(object):
    def searchRange(self, nums, target):
		res = [-1, -1]
		if(not nums):
			return res
		left, right = 0, len(nums) - 1
		while(left < right):
			mid = (left + right) >> 1
			if(nums[mid] < target):
				left = mid + 1
			else:
				right = mid
		if nums[left] != target:
			return res
		res[0], right = left, len(nums) - 1
		while(left < right):
			mid = (left + right) // 2 + 1
			if(nums[mid] <= target):
				left = mid
			else:
				right = mid - 1
		res[1] = right
		return res
