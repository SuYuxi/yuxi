#iterative
class Solution(object):
	def bulbSwitch(self, n):
		if(n <= 0):
			return 0
		elif(n <= 3):
			return 1
		else:
			ans = 0
			for inx in range(1, n):
				count = 0
				for d in range(2, inx+1):
					if(not (inx % d)):
						count += 1	
				if(not (count & 1)):
					ans += 1
			inx = n	
			count = 0
			for d in range(2, inx):
				if(not (inx % d)):
					count += 1	
			if(count & 1):
				ans += 1
			return ans
#math
class Solution(object):
	def bulbSwitch(self, n):
		return int(n**0.5)
