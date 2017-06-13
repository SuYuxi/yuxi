# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
	def mergeTrees(self, t1, t2):
		def preorder(node1, node2):
			node1.val += node2.val
			if(node2.left):
				if(node1.left):
					preorder(node1.left, node2.left)
				else:
					node1.left = node2.left
			if(node2.right):
				if(node1.right):
					preorder(node1.right, node2.right)
				else:
					node1.right = node2.right
		if(not t1):	
			t1 = t2
		elif(t1 and t2):
			preorder(t1, t2)
		return t1
