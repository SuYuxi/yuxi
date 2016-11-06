#bisect
import bisect
class Solution(object):
	def searchInsert(self, nums, target):
		return bisect.bisect_left(nums, target)

#binary search
class Solution(object):
	def searchInsert(self, nums, target):
		left, right = 0, len(nums) - 1
		while(left < right):
			mid = (left + right) >> 1
			if(nums[mid] >= target):
				right = mid
			else:
				left = mid + 1
		return left if nums[left] >= target else left + 1
