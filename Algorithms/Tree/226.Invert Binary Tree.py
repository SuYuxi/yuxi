class Solution(object):
    def invertTree(self, root):
        node = root
        if node:
            node.right, node.left = self.invertTree(node.left), self.invertTree(node.right)
        return root
