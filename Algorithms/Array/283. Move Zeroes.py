class Solution(object):
    def moveZeroes(self, nums):
        nums.sort(key=lambda x:not x)

class Solution(object):
    def moveZeroes(self, nums):
		l = len(nums)
		while(l):
			if(not nums[l-1]):
				nums.pop(l-1)
				nums.append(0)
			l -= 1
