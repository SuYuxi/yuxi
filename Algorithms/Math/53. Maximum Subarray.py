#Kadene's algorithm
class Solution(object):
    def maxSubArray(self, nums):
		maxSum = float('-inf')
		curSum = 0
		for num in nums:
			curSum += num
			maxSum = max(maxSum, curSum)
			if(curSum < 0):
				curSum = 0
		return maxSum
