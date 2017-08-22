#divide and conquer and DP
class Solution(object):
    def maxCoins(self, nums):
		length = len(nums)
		nums = [1] + nums + [1]
		dp = [[0] * len(nums) for i in range(len(nums))]
		for sublen in range(1, length + 1):
			for left in range(1, length - sublen + 2):
				right = left + sublen - 1
				for inx in range(left, right + 1):
					dp[left][right] = max(dp[left][right], nums[left - 1] * nums[inx] * nums[right + 1] + dp[left][inx - 1] + dp[inx + 1][right])
		return dp[1][length]	
