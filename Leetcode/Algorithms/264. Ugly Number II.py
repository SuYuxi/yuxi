#brute force
class Solution(object):
    L = sorted([2 ** a * 3 ** b * 5 ** c for a in range(32) for b in range(20) for c in range(14)])
    def nthUglyNumber(self, n):
        return self.L[n-1]

#deductive
class Solution(object):
    def nthUglyNumber(self, n):
        L = [1]
        p1 = p2 = p3 = 0
        for i in range(1, n):
            while(L[p1] * 2 <= L[-1]):
                p1 += 1
            while(L[p2] * 3 <= L[-1]):
                p2 += 1
            while(L[p3] * 5 <= L[-1]):
                p3 += 1
            L.append(min(L[p1] * 2, L[p2] * 3, L[p3] * 5))
        return L[-1]
