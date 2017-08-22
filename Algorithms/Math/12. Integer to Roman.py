class Solution(object):
	def intToRoman(self, num):
		M = ['', 'M', 'MM', 'MMM']
		C = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
		X = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
		I = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
		return M[num//1000] + C[(num%1000)/100] + X[(num%100)/10] + I[(num%10)]

class Solution(object):
	def intToRoman(self, num):
		values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
		marks = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
		L = ''
		for i in range(len(values)):
			while(num >= values[i]):
				num -= values[i]
				L += marks[i] 
		return L


