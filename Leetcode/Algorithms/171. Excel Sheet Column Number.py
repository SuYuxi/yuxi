class Solution(object):
    def titleToNumber(self, s):
        bit = 0
        num = 0
        for i in s[::-1]:
            num += (ord(i)-ord('A')+1)*(26**bit)
            bit += 1
        return num
