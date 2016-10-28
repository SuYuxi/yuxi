class Solution(object):
    def containsDuplicate(self, nums):
        d = dict()
        for i in nums:
            if (d.setdefault(i,0) == 1):
                return True
            else:
                d[i] = 1
        return False
