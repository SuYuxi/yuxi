class Solution(object):
    def sortColors(self, nums):
		left, right = 0, len(nums) - 1
		inx = 0
		while(inx <= right):
			if(nums[right] == 2):
				right -= 1
			elif(nums[left] == 0):
				left += 1
				if(left > inx):
					inx = left
			elif(nums[inx] == 0):
				nums[left], nums[inx] = 0, nums[left]
				left += 1
			elif(nums[inx] == 2):
				nums[right], nums[inx] = 2, nums[right]
				right -= 1
			else:
				inx += 1
		return

class Solution(object):
    def sortColors(self, nums):
		left, right = 0, len(nums) - 1
		inx = 0
		while(inx <= right):
			while(nums[inx] == 2 and inx < right):
				nums[inx], nums[right] = nums[right], nums[inx]
				right -= 1
			while(nums[inx] == 0 and inx > left):
				nums[inx], nums[left] = nums[left], nums[inx]
				left += 1
			inx += 1
		return
