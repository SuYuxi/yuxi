class Solution(object):
    def intersect(self, nums1, nums2):
        result = []
        d = {'count':0}
        if(len(nums1) > len(nums2)):
            nums1, nums2 = nums2, nums1
        for i in nums1:
            d[i] = d.setdefault(i,0) + 1
            d['count'] += 1
        for j in nums2:
            if(d.setdefault(j,0) > 0):
                result.append(j)
                d[j] -= 1
                d['count'] -= 1
            if(d['count'] == 0):
                break
        return result
		
class Solution(object):
    def intersect(self, nums1, nums2):
        if(not nums1 or not nums2):
            return []
        nums1.sort()
        nums2.sort()
        l1 = len(nums1)
        l2 = len(nums2)
        p1,p2 = 0, 0
        L = []
        while(p1<l1 and p2<l2):
            if(nums1[p1] == nums2[p2]):
                L.append(nums1[p1])
                p1 += 1
                p2 += 1
            elif nums1[p1] < nums2[p2]:
                p1 += 1
            else:
                p2 += 1
        return L
