class Solution(object):
    def search(self, nums, target):
		if(not nums):
			return -1
		left, right = 0, len(nums) - 1
		while(left < right):
			mid = (left + right) >> 1
			if(nums[left] <= nums[mid]):
				if(nums[left] <= target and nums[mid] >= target):
					right = mid
				else:
					left = mid + 1
			else:
				if(nums[mid] < target and nums[right] >= target):
					left = mid + 1
				else:
					right = mid
		return left if nums[left] == target else -1
