class Solution(object):
    def getPermutation(self, n, k):
		factorials = [1]
		for num in range(1, n+1):
			factorials.append(factorials[-1] * num)
		nums = range(1, n+1)
		res = list()
		k -= 1
		for inx in range(1, n+1):
			bit, k = divmod(k, factorials[n - inx])
			res.append(nums[bit])
			nums.pop(bit)
		return ''.join(map(str, res))
