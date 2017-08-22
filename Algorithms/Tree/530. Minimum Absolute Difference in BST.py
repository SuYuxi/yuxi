# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getMinimumDifference(self, root):
		if(not root):
			return None
		res = float('inf')
		stack = list()
		node = root
		pre = float('-inf')
		while(stack or node):
			while(node):
				stack.append(node)
				node = node.left
			if(stack):
				node = stack.pop()
				res = min(res, node.val - pre)
				pre = node.val
				node = node.right
		return res
