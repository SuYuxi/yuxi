#Math
class Solution(object):
    def numberOfBoomerangs(self, points):
		res = 0
		for p1 in points:
			D = dict()
			for p2 in points:
				distance = (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2
				if(distance in D):
					res += D[distance]
					D[distance] += 2
				else:
					D[distance] = 2
		return res
		
class Solution(object):
    def numberOfBoomerangs(self, points):
		length = len(points)
		res = 0
		for p1 in points:
			D = dict()
			for p2 in points:
				distance = (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2
				D[distance] = D.setdefault(distance, 0) + 1 
			for value in D.values():
				res += value * (value - 1)
		return res
