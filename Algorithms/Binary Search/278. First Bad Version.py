# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
	def firstBadVersion(self, n):
		left, right = 1, n 
		while(left < right):
			mid = (left + right) >> 1
			if(isBadVersion(mid)):
				right = mid
			else:
				left = mid + 1
		return left if isBadVersion(left) else 0 #if there is no badversion return 0
