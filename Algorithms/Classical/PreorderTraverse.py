# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def preorderTraverse(root):
	stack = list()
	node = root
	pre = None
	while(stack or node):
		while(node):
			stack.append(node)
			node = node.left
		if(stack):
			node = stack[-1]
			if(not node.right or node.right == pre):
				print(node.val)
				stack.pop()
				pre = node
				node = None
			else:
				node = node.right
	return root
