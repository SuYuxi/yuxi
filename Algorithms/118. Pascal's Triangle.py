class Solution(object):
    def generate(self, numRows):
        L = [[1],[1,1]]
        if(numRows <= 2):
            return L[:numRows]
        for i in range(2,numRows):
            L.append([1])
            for j in range(1,i):
                L[i].append(L[i-1][j-1] + L[i-1][j])
            L[i].append(1)
        return L
            
class Solution(object):
    def generate(self, numRows):
        L = [[1]]
        for i in range(1, numRows):
            L.append(map(lambda x, y: x + y, [0] + L[i-1], L[i-1] + [0]))
        return L[:numRows]
