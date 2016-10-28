class Solution(object):
    def majorityElement(self, nums):
        return sorted(nums)[len(nums)//2]

class Solution(object):
    def majorityElement(self, nums):
        count = 1
        major = nums[0]
        for i in range(1,len(nums)):
            if(count == 0):
                major = nums[i]
                count = 1
            elif(major == nums[i]):
                count += 1
            else:
                count -= 1
        return major
