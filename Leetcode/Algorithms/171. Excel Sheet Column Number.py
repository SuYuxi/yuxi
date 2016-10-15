class Solution(object):
    def titleToNumber(self, s):
        num = 0
        for i in s:
            num = num*26 + (ord(i)-ord('A')+1)
        return num
