class Solution(object):
    def matrixReshape(self, nums, r, c):
		flat = sum(nums, [])
		if(len(flat) != r * c):
			return nums
		rLen = len(nums)
		lLen = len(nums[0])
		count = 0
		reshape = list()
		for _ in range(r):
			reshape.append([None] * c)
		for row in nums:
			for val in row:
				reshape[count // c][count % c] = val
				count += 1
		return reshape

class Solution(object):
    def matrixReshape(self, nums, r, c):
        flat = sum(nums, [])
        if len(flat) != r * c:
            return nums
        tuples = zip(*([iter(flat)] * c))
        return map(list, tuples)
