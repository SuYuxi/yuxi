class Solution(object):
    def intersection(self, nums1, nums2):
        s1 = set()
        r = set()
        for i in nums1:
            s1.add(i)
        for j in nums2:
            if j in s1:
                r.add(j)
        return list(r)
