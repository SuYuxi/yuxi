class Solution(object):
    def findRestaurant(self, list1, list2):
		hashmap = dict()
		res = list()
		minSum = float('inf')
		for inx, name in enumerate(list1):
			hashmap[name] = inx
		for inx, name in enumerate(list2):
			if(name in hashmap):
				count = inx + hashmap[name]
				if(count < minSum):
					minSum = count
					res = [name]
				elif(count == minSum):
					res.append(name)
		return res
