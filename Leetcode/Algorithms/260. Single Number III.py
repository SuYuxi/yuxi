class Solution(object):
	def singleNumber(self, nums):
		xor = nums[0]
		for i in nums[1:]:
			xor ^= i
		lastbit = xor & ~(xor - 1)
		A, B = xor, xor
		for i in nums:
			if(i & lastbit):
				A = A ^ i
			else:
				B = B ^ i
		return [A, B]
