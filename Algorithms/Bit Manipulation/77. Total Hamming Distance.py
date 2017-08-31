class Solution(object):
    def totalHammingDistance(self, nums):
		return sum(x.count('0') * x.count('1') for x in zip(*map('{:0>32b}'.format, nums)))
		
class Solution(object):
    def totalHammingDistance(self, nums):
		res = 0
		n = len(nums)
		for i in range(32):
			bits = 0
			for num in nums:
				bits += (num >> i) & 1
			res += bits * (n - bits)
		return res
