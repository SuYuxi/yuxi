class Solution:
	def addOneRow(self, root, v, d):
		if(d == 1):
			root, root.left = TreeNode(v), root
			return root
		stack = [root]
		depth = 1
		while(depth < d - 1):
			nextstack = list()
			while(stack):
				node = stack.pop()
				if(node.left):
					nextstack.append(node.left)
				if(node.right):
					nextstack.append(node.right)
			stack = nextstack
			depth += 1

		while(stack):
			node = stack.pop()
			node.left, node.left.left = TreeNode(v), node.left 
			node.right, node.right.right = TreeNode(v), node.right 
		return root
