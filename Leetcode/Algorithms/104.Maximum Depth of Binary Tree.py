#iterative
class Solution(object):
    def maxDepth(self, root):
        if not root:
            return 0
        stack = [root]
        depth = 1
        while(stack):
            nextlevel = []
            while(stack):
                node = stack.pop()
                if node.right:
                    nextlevel.append(node.right)
                if node.left:
                    nextlevel.append(node.left)
            if nextlevel:
                depth += 1
            stack = nextlevel    
        return depth
#recursive
def maxDepth(self, root):
    def dfs(level, root, res):
        if root:
            if level > res[0]: 
                res[0] = level
            dfs(level+1, root.left, res)
            dfs(level+1, root.right,res)
    res = [0]
    dfs(1, root, res)
    return res[0]
