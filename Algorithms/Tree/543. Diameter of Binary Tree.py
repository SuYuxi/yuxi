# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
	def diameterOfBinaryTree(self, root):
		self.diameter = 1
		def depth(root):
			if(not root): return 0
			leftDepth = depth(root.left)
			rightDepth = depth(root.right)
			self.diameter = max(self.diameter, leftDepth + rightDepth + 1)
			return 1 + max(leftDepth, rightDepth)
		depth(root)
		return self.diameter - 1
