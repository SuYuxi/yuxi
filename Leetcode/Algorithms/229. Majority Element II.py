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
