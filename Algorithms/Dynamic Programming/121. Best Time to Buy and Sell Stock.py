#Forward
class Solution(object):
    def maxProfit(self, prices):
        if(not prices):
            return 0
        minP = prices[0]
        maxPro = 0
        for i in prices:
			if(i <= minP):
            	minP = i
			else:
            	maxPro = max(maxPro, i-minP)
        return maxPro

#Backward
class Solution(object):
	def maxProfit(self, prices):
		maxP = 0
		maxPro = 0
		for i in prices[::-1]:
			if(i > maxP):
				maxP = i
			else:
				maxPro = max(maxPro, maxP - i)
		return maxPro

#Kadane's Algorithm
#Max sum Contiguous subarray search
class Solution(object):
	def maxProfit(self, prices):
		L = []
		for i in range(1, len(prices)):
			L.append(prices[i] - prices[i-1])
		maxCur = 0
		maxSofar = 0
		for i in L:
			maxCur = max(0, maxCur + i)
			maxSofar = max(maxSofar, maxCur)
		return maxSofar

#Lite version
class Solution(object):
	def maxProfit(self, prices):
		maxCur = 0
		maxSofar = 0
		for i in range(1, len(prices)):
			maxCur = max(0, maxCur + prices[i] - prices[i-1])
			maxSofar = max(maxSofar, maxCur)
		return maxSofar
