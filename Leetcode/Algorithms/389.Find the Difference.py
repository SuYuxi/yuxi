class Solution(object):
    def findTheDifference(self, s, t):
        ans = 0
        for i in s+t:
            ans ^= ord(i)
        return chr(ans)
