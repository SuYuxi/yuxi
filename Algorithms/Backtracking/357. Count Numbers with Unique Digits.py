class Solution(object):
	def countNumbersWithUniqueDigits(self, n):
		if(n == 0):
			return 1
		num = 10
		count = 9
		for i in range(2, min(11, n + 1)):
			count *= 11 - i	
			num += count
		return num

class Solution(object):
	def countNumbersWithUniqueDigits(self, n):
		L = [1, 9, 9, 8, 7, 6, 5, 4, 3, 2, 1]
		return sum((reduce(lambda x,y:x * y,L[:i+1])) for i in range(n + 1))

class Solution(object):
	def countNumbersWithUniqueDigits(self, n):
		choices = [1, 9, 9, 8, 7, 6, 5, 4, 3, 2, 1]
		ans, product = 0, 1	
		for i in range(min(n+1, 11)):
			product *= choices[i]
			ans += product
		return ans

#Backtracking
class Solution(object):
	def countNumbersWithUniqueDigits(self, n):
		def BackTrack(target, bits, inx):
			if(target == inx):
				return 1
			count = 0
			start = 0 if inx != 0 else 1
			for i in range(start, 10):
				if(not bits[i]):
					bits[i] = 1
					count += BackTrack(target, bits, inx + 1)
					bits[i] = 0
			return count 

		count = 0	
		bits = [0] * 10
		for i in range(min(11,n+1)):
			count += BackTrack(i, bits, 0)
		return count
