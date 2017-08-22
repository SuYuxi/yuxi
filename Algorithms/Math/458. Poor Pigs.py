class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
		pigs = 0
		while((minutesToTest // minutesToDie + 1) ** pigs < buckets):
			pigs += 1
		return pigs

import math
class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
		return int(math.ceil(math.log(buckets, minutesToTest // minutesToDie + 1)))
		
