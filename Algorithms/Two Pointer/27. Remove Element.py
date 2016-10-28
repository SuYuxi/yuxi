class Solution(object):
    def removeElement(self, nums, val):
        l, r = 0, len(nums)-1
        while l <= r:
            while l <= r and nums[l] != val:
                l += 1
            while l <= r and nums[r] == val:
                r -= 1
            if l <= r:
                nums[l], nums[r] = nums[r], nums[l]
        nums = nums[:l]
        return l
