#slower
class Solution(object):
    def nextPermutation(self, nums):
		length = len(nums)
		i = length - 2
		j = length - 1
		while(i >= 0):
			while(i <= j):
				if(nums[i] < nums[j]):
					nums[i], nums[j] = nums[j], nums[i]
					nums[i+1:] = sorted(nums[i+1:])
					#nums[i+1:] = nums[i+1:][::-1]
					return
				j -= 1
			j = length -1
			i -= 1
		nums[:] = nums[::-1]
		return

#better
class Solution(object):
    def nextPermutation(self, nums):
		def reverse(start, end):
			while(start < end):
				nums[start], nums[end] = nums[end], nums[start]
				start += 1
				end -= 1
			return

		length = len(nums)
		i = length - 2
		while(i >= 0 and nums[i] >= nums[i + 1]):
			i -= 1
		if(i >= 0):
			j = length - 1
			while(nums[i] >= nums[j]): 
				j -= 1
			nums[i], nums[j] = nums[j], nums[i]
		reverse(i+1, length - 1)
		return


