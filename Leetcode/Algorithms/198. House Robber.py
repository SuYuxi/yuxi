class Solution(object):
    def rob(self, nums):
        preYesMax = preNoMax = 0
        for i in nums:
            preNoMax, preYesMax = max(preYesMax, preNoMax), preNoMax + i
        return max(preNoMax, preYesMax)
