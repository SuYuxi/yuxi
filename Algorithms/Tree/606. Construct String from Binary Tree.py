# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

#recursion
class Solution(object):
	def tree2str(self, t):
		def preorder(root):
			if(not root): return ''
			left = '({})'.format(preorder(root.left)) if (root.left or root.right) else ''
			right = '({})'.format(preorder(root.right)) if root.right else ''
			return '{}{}{}'.format(root.val, left, right)
		return preorder(t)


#iteration
class Solution(object):
	def tree2str(self, t):
		stack = list()
		stack.append(t)
		ret = ''
		visited = set()
		while(stack):
			node = stack[-1]
			if(node not in visited):
				visited.add(node)
				if(node):
					ret += '({}'.format(node.val)
					if(node.right):
						stack.append(node.right)
						if(not node.left):
							ret += '()'
					if(node.left):
						stack.append(node.left)
				else:
					ret += '('
			else:
				stack.pop()
				ret += ')'
		return ret[1:-1]

