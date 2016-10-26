class Solution(object):
	def maxProfit(self, prices):
		maxprofit = 0
		for i in range(1, len(prices)):
			p = prices[i] - prices[i-1]
			if(p > 0):
				maxprofit += p
		return maxprofit

class Solution(object):
	def maxProfit(self, prices):
		length = len(prices)
		if(length < 2):
			return 0
		maxprofit = 0
		peak = valley = prices[0]
		i = 0
		while(i < length - 1):
			while(i < length - 1 and prices[i+1] <= prices[i]):
				i += 1
			valley = prices[i]
			while(i < length - 1 and prices[i+1] >= prices[i]):
				i += 1
			peak = prices[i]
			maxprofit += peak - valley
		return maxprofit
