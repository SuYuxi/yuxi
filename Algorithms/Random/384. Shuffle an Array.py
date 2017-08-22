import random
class Solution(object):
	def __init__(self, nums):
		self.nums = nums[:]
		self.size = len(nums)
		
	def reset(self):
		return self.nums

	def shuffle(self):
		new = self.nums[:]
		for i in range(self.size):
			inx = random.randint(0, self.size - 1)
			new[i], new[inx] = new[inx], new[i]	
		return new
