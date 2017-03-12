class Solution(object):
	def threeSum(self, nums):
		res = []
		nums.sort()
		l = len(nums)
		for left in range(l - 2):
			if(left > 0 and nums[left] == nums[left-1]):
				continue
			mid, right = left+1, l-1
			while(mid < right):
				ref = nums[left] + nums[mid] + nums[right]
				if(ref < 0):
					mid += 1
				elif(ref > 0):
					right -= 1
				else:
					res.append([nums[left], nums[mid], nums[right]])
					while(mid < right and nums[mid] == nums[mid+1]):
						mid += 1
					while(mid < right and nums[right] == nums[right-1]):
						right -= 1
					mid += 1
					right -= 1
		return res
