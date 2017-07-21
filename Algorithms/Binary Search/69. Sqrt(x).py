class Solution(object):
    def mySqrt(self, x):
		root = 1
		while(root ** 2 <= x):
			root *= 2
		root //= 2
		residual = root // 2
		while(residual > 0):
			if((root + residual) ** 2 <= x):
				root += residual
			residual //= 2
		return root

class Solution(object):
    def mySqrt(self, x):
		left, right = 0, x 
		while(left < right):
			mid = math.ceil((left + right) / 2.0)
			if(mid ** 2 <= x):
				left = mid
			else:
				right = mid - 1
		return int(left)
