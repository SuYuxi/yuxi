class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
		ans = 0
		cnt = 0
		for num in nums:
			if(not num):
				ans = max(ans, cnt)
				cnt = 0 
			else:
				cnt += 1
		return max(ans, cnt)
