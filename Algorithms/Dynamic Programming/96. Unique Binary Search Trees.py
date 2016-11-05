#Dynamic programming with hashmap
class Solution(object):
	def numTrees(self, n):
		def DP(num):
			if(num in hashmap):
				return hashmap[num]
			if(not num or num == 1):
				return 1
			count = 0	
			for i in range(1, num + 1):
				count += DP(i-1) * DP(num - i)
			hashmap[num] = count
			return count
		hashmap = {}
		return DP(n)
	
#Dynamic programming with state array 
#a little faster than hashmap when length is small
class Solution(object):
	def numTrees(self, n):
		def DP(num):
			if(hashmap[num]):
				return hashmap[num]
			count = 0	
			for i in range(1, num + 1):
				count += DP(i-1) * DP(num - i)
			hashmap[num] = count
			return count
		hashmap = [None] * (n + 1)
		hashmap[0] = hashmap[1] = 1
		return DP(n)
