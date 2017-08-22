class Solution(object):
    def arrayNesting(self, nums):
		res = 0
		D = set()
		for start in nums:
			if(start in D):
				continue
			count = 1
			num = nums[start]
			while(num != start):
				D.add(num)
				count += 1
				num = nums[num]
			res = max(res, count)
		return res
