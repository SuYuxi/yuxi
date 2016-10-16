class Solution(object):
    def countBits(self, num):
        L = [0] * (num + 1)
        order = 1
        counter = 0
        for i in range(1, num+1):
            if(i % order == 0):
				L[i] = 1
                counter = 0
				order *= 2
            else:
                counter += 1
                L[i] = 1 + L[counter]
        return L

class Solution(object):
    def countBits(self, num):
        L = [0] * (num + 1)
        for i in range(1, num + 1):
            L[i] = L[i & (i-1)] + 1
        return L
