class Solution(object):
    def addStrings(self, num1, num2):
        l1 = len(num1)
        l2 = len(num2)
        carry = 0
        if l1 < l2:
            num1 = '0' * (l2-l1) + num1
        else:
            num2 = '0' * (l1-l2) + num2
        
        s = str()
        for i in range(len(num1)-1,-1,-1):
            ans = ord(num1[i])+ord(num2[i])-2*ord('0')+carry
            s = str(ans % 10) + s
            carry = ans // 10
        if carry == 1:
            s = '1'+ s
        return s
