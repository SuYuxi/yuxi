class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = dict()
        flag = 0
        num = 0
        for i in s:
            d[i] = d.setdefault(i,0) + 1
        for j in d:
            flag |= d[j]&1
            num += (d[j] >> 1) <<1
        return num + flag
