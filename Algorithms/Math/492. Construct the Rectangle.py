class Solution(object):
	def constructRectangle(self, area):
		sqr = int(area ** 0.5)
		for i in range(sqr, 0, -1):
			if(not area % i):
				return [area / i, i]

