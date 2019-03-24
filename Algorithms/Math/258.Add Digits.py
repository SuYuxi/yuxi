#iterative
class Solution(object):
    def addDigits(self, num):
        while(num > 9):
            sum = 0
            while(num != 0):
                sum += num%10
                num //= 10
            num = sum
        return num

#mathmatic theory
class Solution(object):
    def addDigits(self, num):
        return (num % 9 or 9) if num != 0 else 0
# 1 + (num - 1) % 9
