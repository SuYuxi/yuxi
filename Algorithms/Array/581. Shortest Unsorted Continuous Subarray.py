class Solution(object):
    def findUnsortedSubarray(self, nums):
		length = len(nums)
		inx = 1
		while(inx < length):
			if(nums[inx] < nums[inx-1]):
				left = inx - 2
				break
			inx += 1
		if(inx == length or length == 0):
			return 0
		inx = length - 2
		while(inx >= 0):
			if(nums[inx] > nums[inx+1]):
				right = inx + 2
				break
			inx -= 1
		Min = min(nums[left+1:right])
		Max = max(nums[left+1:right])
		while(left >= 0 and nums[left] > Min):
			left -= 1
		while(right < length and nums[right] < Max):
			right += 1
		return right - left - 1

class Solution(object):
    def findUnsortedSubarray(self, nums):
		length = len(nums)
		left, right = length - 1, 0
		stack = list()
		inx = 0
		while(inx < length):
			while(stack and nums[stack[-1]] > nums[inx]):
				left = min(left, stack.pop())
			stack.append(inx)
			inx += 1
		stack = list()
		inx = length - 1
		while(inx >= left):
			while(stack and nums[stack[-1]] < nums[inx]):
				right = max(right, stack.pop())
			stack.append(inx)
			inx -= 1
		return right - left + 1 if right > left else 0

class Solution(object):
    def findUnsortedSubarray(self, nums):
		new = sorted(nums)
		left, right = 0, len(nums) - 1
		while(left < len(nums)):
			if(new[left] != nums[left]):
				break
			left += 1
		while(right > left):
			if(new[right] != nums[right]):
				break
			right -= 1
		return right - left + 1 if (left < right) else 0
