class Solution(object):
    def search(self, nums, target):
		if(not nums):
			return False
		left, right = 0, len(nums) - 1
		while(left < right):
			mid = (left + right) >> 1
			if(nums[mid] == target):
				return True
			if(nums[left] < nums[mid]):
				if(nums[left] <= target < nums[mid]):
					right = mid - 1
				else:
					left = mid + 1
			elif(nums[left] > nums[mid]):
				if(nums[mid] < target <= nums[right]):
					left = mid + 1
				else:
					right = mid - 1
			else:
				left += 1
		return True if nums[left] == target else False
