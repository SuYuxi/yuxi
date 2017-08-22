class Solution(object):
	def fourSum(self, nums, target):
		result = list()
		nums = sorted(nums)
		for n1 in range(len(nums)):
			if(4 * nums[n1] > target):
				return(result)
			for n4 in range(len(nums) - 1, n1 + 2, -1):
				if(4 * nums[n4] < target):
					break
				n2 = n1 + 1
				n3 = n4 - 1
				aim = target - nums[n1] - nums[n4]
				while(n2 < n3):
					if(nums[n2] + nums[n3] < aim):
						n2 += 1
					elif(nums[n2] + nums[n3] > aim):
						n3 -= 1
					else:
						array = [nums[n1], nums[n2], nums[n3], nums[n4]]
						if(array not in result):
							result.append(array)
						n2 += 1
						n3 -= 1
		return(result)
