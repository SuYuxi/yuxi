class Solution(object):
    def jump(self, nums):
		steps, curBound, maxReach, goal = 0, 0, 0, len(nums) - 1
		for pos in range(goal):
			distance = pos + nums[pos]
			if(distance >= goal):
				return steps + 1
			if(distance > maxReach):
				maxReach = distance
			if(pos == curBound):
				steps += 1
				curBound = maxReach
		return steps
		
class Solution(object):
    def jump(self, nums):
		length = len(nums)
		start, end, steps = 0, 0, 0
		while(end < length - 1):
			steps += 1
			maxReach = end + 1
			for pos in range(start, end + 1):
				reach = pos + nums[pos]
				if(reach >= length - 1):
					return steps
				maxReach = max(maxReach, reach)
			start, end = end + 1, maxReach
		return steps
