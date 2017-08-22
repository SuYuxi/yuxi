class Solution(object):
    def minPathSum(self, grid):
		lenRow, lenCol = len(grid), len(grid[0])
		dp = [float('inf')] * lenCol
		dp[0] = 0
		for row in range(lenRow):
			dp[0] += grid[row][0]
			for col in range(1, lenCol):
				dp[col] = grid[row][col] + min(dp[col], dp[col-1])
		return dp[-1]
