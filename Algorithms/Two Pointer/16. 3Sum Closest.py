class Solution(object):
    def threeSumClosest(self, nums, target):
		l = len(nums)
		if(l < 3):
			return 0
		res = sum(nums[0:3])
		dif = abs(res - target)
		nums.sort()
		for left in range(l - 2):
			if(sum(nums[left:left+3]) > target + dif):
				break
			if(nums[left] + nums[l-2] + nums[l-1] < target - dif):
				continue
			if(left > 0 and nums[left] == nums[left-1]):
				continue
			mid, right = left+1, l-1
			while(mid < right):
				temp = nums[left] + nums[mid] + nums[right]
				ref = abs(temp - target)
				if(ref < dif):
					dif = ref
					res = temp
				if(temp < target):
					mid += 1
				elif(temp > target):
					right -= 1
				else:
					return temp
		return res

