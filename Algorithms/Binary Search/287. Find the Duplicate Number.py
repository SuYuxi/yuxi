#binary search
class Solution(object):
	def findDuplicate(self, nums):
		left, right = 1, len(nums) - 1
		while(left < right):
			mid = (left + right) >> 1
			count = 0
			for i in nums:
				if(i <= mid):
					count += 1
			if(count <= mid):
				left = mid + 1
			else:
				right = mid
		return left

#hash
class Solution(object):
	def findDuplicate(self, nums):
		d = dict()
		for i in nums:
			if(d.setdefault(i, 0)):
				return i
			d[i] += 1 

#bit manipulation
class Solution(object):
	def findDuplicate(self, nums):
		ans = 0
		mask = 0x1
		for i in range(32):
			a = b = 0
			for j in range(1, len(nums) + 2):
				a += j & mask
				b += nums[j] & mask
			ans += mask if b > a else 0
			mask <<= 1
		return ans
