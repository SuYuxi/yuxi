#recursive
class Solution(object):
    def preorderTraversal(self, root):
		def traverse(node):
			if(node):
				L.append(node.val)
				traverse(node.left)
				traverse(node.right)
			return	
		L = []
		traverse(root)
		return L

#iterative
class Solution(object):
	def preorderTraversal(self, root):
		stack = []
		L = []
		node = root
		while(node or len(stack)):
			if(node):
				L.append(node.val)
				stack.append(node.right)
				node = node.left
			else:
				node = stack.pop()
		return L
		
#morris traversal
class Solution(object):
	def preorderTraversal(self, root):
		node = root
		L = []
		while(node):
			if(not node.left):
				L.append(node.val)
				node = node.right
			else:
				pre = node.left
				while(pre.right and pre.right != node):
					pre = pre.right
				if(not pre.right):
					pre.right = node
					L.append(node.val)
					node = node.left
				else:
					pre.right = None
					node = node.right
		return L
