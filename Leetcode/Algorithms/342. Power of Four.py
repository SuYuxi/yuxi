class Solution(object):
    def isPowerOfFour(self, num):
        return (num & 0x55555555) > 0 and not (num & num-1)
class Solution {
	def isPowerOfFour(self, num):
        return ((num-1)&num)==0 && (num-1)%3==0
