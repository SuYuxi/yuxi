class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        def findNode(root, node):
            route = []
            def traverse(pointer):
                route.append(pointer)
                if (pointer == node):
                    return 1
                if(pointer.left and traverse(pointer.left)):
                    return 1
                if(pointer.right and traverse(pointer.right)):
                    return 1
                route.pop()
                return 0
            if(not root):
                return None
            traverse(root)
            return route
        sp = findNode(root, p)
        sq = findNode(root, q)
        if(not sp or not sq):
            return None
        inx = min(len(sp), len(sq))
        sp, sq = sp[:inx], sq[:inx]
        for i in range(inx):
            np, nq = sp.pop(), sq.pop()
            if(np == nq):
                return np

#recursive
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        if root in (None, p, q):
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        return root if left and right else left or right
