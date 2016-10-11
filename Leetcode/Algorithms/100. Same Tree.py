class Solution(object):
    def isSameTree(self, p, q):
        if(not (p and q)):
            return p == q
        elif(p.val != q.val):
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        
