class Solution(object):
	def convert(self, s, numRows):
		if(numRows <= 1):
			return s
		string = [''] * numRows
		row = 0
		for inx, char in enumerate(s):
			if(row == 0):
				step = 1
			elif(row == numRows - 1):
				step = -1
			string[row] += char
			row += step
		ans = ''
		for i in string:
			ans += i
		return ans
