# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findTilt(self, root):
		def traverse(node):
			if(not node):
				return 0
			left = traverse(node.left)
			right = traverse(node.right)
			res[0] += abs(left - right)
			return node.val + left + right
		res = [0]
		traverse(root)
		return res[0]
