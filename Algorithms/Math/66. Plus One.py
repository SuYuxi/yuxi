class Solution(object):
    def plusOne(self, digits):
        carry = 1
        for i in range(len(digits)-1,-1,-1):
            temp = digits[i] + carry
            digits[i] = temp % 10
            carry = temp // 10
        if(carry != 0):
            digits.insert(0, carry)
        return digits

class Solution(object):
    def plusOne(self, digits):
        result = 1
        l = len(digits)
        for i in range(l):
            result += digits[l - 1 - i] * (10 ** i) 
        return [int(i) for i in str(result)]
