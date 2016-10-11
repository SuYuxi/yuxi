class Solution(object):
    def isHappy(self, n):
        looped = set()
        while(n > 1 and n not in looped):
            looped.add(n)
            S = 0
            while(n):
                S += (n%10)**2
                n //= 10
            n = S
        return n == 1
