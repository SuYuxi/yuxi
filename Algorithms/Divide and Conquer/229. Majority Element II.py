from collections import defaultdict
class Solution(object):
    def majorityElement(self, nums):
        d = defaultdict(int)
        result = []
        for i in nums:
            d[i] += 1
        l = len(nums)/3
        for j in d:
            if (d[j] > l):
                result.append(j)
                if (len(result) >= 2):
                    return result
        return result

#Boyer-Moore Majority Vote algorithm
from collections import defaultdict
class Solution(object):
    def majorityElement(self, nums):
		if(not nums):
			return []
		s1, s2 = None, None
		count1, count2 = 0, 0
		for i in nums:
			if(i == s1):
				count1 += 1
			elif(i == s2):
				count2 += 1
			elif(count1 == 0):
				s1 = i
				count1 = 1
			elif(count2 == 0):
				s2 = i
				count2 = 1
			else:
				count1 -= 1
				count2 -= 1
		return [i for i in (s1, s2) if nums.count(i) > len(nums) // 3]
