class Solution(object):
	def distributeCandies(self, candies):
		return min(len(candies)/2, len(set(candies)))

class Solution(object):
	def distributeCandies(self, candies):
		s = set()
		kind = 0
		inx = 0
		while (inx < len(candies) and kind < len(candies) / 2):
			if(candies[inx] not in s):
				s.add(candies[inx])
				kind += 1
			inx += 1
		return kind
