class Solution(object):
    def isPowerOfTwo(self, n):
        return True if (not (n & n-1) and n) else False
