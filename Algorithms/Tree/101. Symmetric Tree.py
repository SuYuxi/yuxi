#iterative
class Solution(object):
   	def isSymmetric(self, root):
        layer = [root]
        temp = []
        children = []
        while (layer):
            for i in layer:
                if(i):
                    temp.append(i.left)
                    temp.append(i.right)
                    children.append(i.left.val) if(i.left) else children.append(None)
                    children.append(i.right.val) if(i.right) else children.append(None)
            if(children != children[::-1]):
                return False
            layer = temp
            temp = []
            children = []
        return True

#recursive
class Solution(object):
    def isSymmetric(self, root):
        def isMirror(n1, n2):
            if(not(n1 or n2)):
                return True
            elif(n1 and n2 and n1.val == n2.val):
                return isMirror(n1.left, n2.right) and isMirror(n1.right, n2.left)
            else:
                return False
        if(not root):
            return True
        return isMirror(root.left, root.right)
        
