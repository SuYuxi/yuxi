class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
		lenRow, lenCol = len(obstacleGrid), len(obstacleGrid[0]) 
		dp = [0] * lenCol
		dp[0] = 1
		for row in range(lenRow):
			for col in range(lenCol):
				if(obstacleGrid[row][col] == 1):
					dp[col] = 0
				elif(col > 0):
					dp[col] += dp[col-1]
		return dp[-1]
