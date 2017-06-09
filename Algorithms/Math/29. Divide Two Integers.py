#fast
class Solution(object):
	def divide(self, dividend, divisor):
		positive = (divisor > 0) is (dividend > 0)
		if(not divisor):
			return(float('inf')) if positive else float('-inf') 
		divisor = abs(divisor)
		dividend = abs(dividend)
		quotient = 0
		order = 1
		subtracter = divisor
		while(dividend >= subtracter):
			subtracter <<= 1
			order <<= 1
		order >>= 1
		subtracter >>= 1
		while(dividend >= divisor):
			if(dividend >= subtracter):
				dividend -= subtracter
				quotient += order
			subtracter >>= 1
			order >>= 1
		if(not positive):
			quotient = -quotient 
		return min(max(quotient, -2147483648), 2147483647)


#slow
class Solution(object):
	def divide(self, dividend, divisor):
		positive = (divisor > 0) is (dividend > 0)
		if(not divisor):
			return(float('inf')) if positive else float('-inf') 
		divisor = abs(divisor)
		dividend = abs(dividend)
		quotient = 0
		while(dividend >= divisor):
			order = 1
			temp = divisor
			while(dividend >= temp):
				dividend -= temp
				quotient += order
				temp <<= 1	
				order <<= 1
		if(not positive):
			quotient = -quotient 
		return min(max(quotient, -2147483648), 2147483647)
