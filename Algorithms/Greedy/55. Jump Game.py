#Top-Down
class Solution(object):
    def canJump(self, nums):
		maxstep = 0
		length = len(nums)
		for inx in range(length - 1):
			if(not nums[inx] and maxstep <= inx):
				return False
			maxstep = max(maxstep, inx + nums[inx])
		return True

#Bottom-Up		
class Solution(object):
    def canJump(self, nums):
		length = len(nums)
		lastPos = length - 1
		for inx in reversed(range(length)):
			if(inx + nums[inx] >= lastPos):
				lastPos = inx
		return lastPos == 0
