class Solution(object):
    def judgeSquareSum(self, c):
		root = int((0.5
		a = 0
		while(a <= root):
			b = (c - a**2) ** 0.5
			if(b == b // 1):
				return True
			a += 1
		return False

#Fermat Theorem
class Solution(object):
    def judgeSquareSum(self, c):
		for num in range(2, int(c ** 0.5) + 1):
			count = 0
			if(not c % num):
				while(not c % num):	
					count += 1
					c /= num
				if(num % 4 == 3 and count % 2):
					return False
			if(c == 1):
				return True
		return c % 4 != 3
