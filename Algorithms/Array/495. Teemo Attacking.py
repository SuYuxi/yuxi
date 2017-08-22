class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
		pre = float('-inf')
		res = 0
		for time in timeSeries:
			if(time < pre):
				res += time + duration - pre
			else:
				res += duration
			pre = time + duration
		return res
