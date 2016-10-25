class Solution(object):
	def numberOfArithmeticSlices(self, A):
		ans = 0
		if(len(A) > 1):
			diff = [A[i] - A[i-1] for i in range(1, len(A))]
			count = 2
			pre = diff[0]
			for i in range(1, len(diff)):
				if diff[i] == pre:
					count += 1
				else:
					ans += (count - 2 ) * (count - 1) / 2
					pre = diff[i]
					count = 2
			ans += (count - 2 ) * (count - 1) / 2
		return ans
