class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
		plants = 0
		empty = 1
		for plot in flowerbed:
			if(not plot):
				empty += 1
			else:
				if(empty > 2):
					plants += (empty - 1) // 2
				empty = 0
		plants += empty // 2
		return plants >= n
