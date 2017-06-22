# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def convertBST(self, root):
		def preorder(node):
			if(node):
				preorder(node.left)
				values.append(node.val)
				preorder(node.right)
			return
		def reversePreorder(node):
			global cum
			if(node):
				reversePreorder(node.right)
				cum += values.pop()
				node.val = cum
				reversePreorder(node.left)
			return
		values = list()
		preorder(root)
		global cum
		cum = 0
		reversePreorder(root)
		return root
