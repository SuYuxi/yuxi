# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def printTree(self, root):
		def fill(node, height, left, right):
			stack = [(node, left, right)]
			while(stack):
				nextlevel = list()
				while(stack):
					node, left, right = stack.pop()
					mid = (left + right) >> 1
					res[height][mid] = str(node.val)
					if(node.left):	
						nextlevel.append((node.left, left, mid - 1))
					if(node.right):
						nextlevel.append((node.right, mid + 1, right))
				stack = nextlevel
				height += 1
# Get tree height
		height = 0
		stack = [root]
		while(stack):
			height += 1
			nextlevel = list()
			while(stack):
				node = stack.pop()
				if(node.left):
					nextlevel.append(node.left)
				if(node.right):
					nextlevel.append(node.right)
			stack = nextlevel
# Generate tree matrix
		length = (1 << height) - 1	
		res = [[""] * length for _ in range(height)]
		fill(root, 0, 0, length - 1)
		return res
