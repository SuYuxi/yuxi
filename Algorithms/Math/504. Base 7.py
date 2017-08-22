class Solution(object):
    def convertToBase7(self, num):
		if(not num):
			return '0'
		if(num < 0):
			return '-' + self.convertToBase7(-num)
		res = ''
		while(num):
			res = str(num % 7) + res
			num //= 7
		return res
