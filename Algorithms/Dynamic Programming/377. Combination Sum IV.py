#hashmap
class Solution(object):
	def combinationSum4(self, nums, target):
		hash = dict()
		def DP(nums, target):
			count = 0
			if(not nums or target < 0):
				return 0 
			elif(target in hash):
				return hash[target]
			elif(target == 0):
				return 1
			else:
				for i in nums:	
					count += DP(nums, target - i)
				hash[target] = count
			return count
		return DP(nums, target)

#deductive
class Solution(object):
	def combinationSum4(self, nums, target):
		nums.sort()
		combs = [None] + [0] * target
		for i in range(target + 1):
			for num in nums:
				if(num > i):
					break
				elif(num == i):
					combs[i] += 1
				else:
					combs[i] += combs[i - num]
		return combs[target]
		

