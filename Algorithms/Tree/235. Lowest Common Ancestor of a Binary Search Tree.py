class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        point = root
        while(point):
            if(max(p.val, q.val) < point.val):
                point = point.left
            elif(min(p.val, q.val) > point.val):
                point = point.right
            else:
                return point
        return None
