#recursive
class Solution(object):
	def inorderTraversal(self, root):
		def inorder(node):
			if(not node):
				return
			inorder(node.left)
			L.append(node.val)
			inorder(node.right)	
		L = []
		inorder(root)
		return L

#iterative
class Solution(object):
	def inorderTraversal(self, root):
		L = []
		stack = []
		node = root
		while(node or stack):	
			if(node):
				stack.append(node)
				node = node.left
			else:
				node = stack.pop()
				L.append(node.val)
				node = node.right
		return L
		
#morris traversal	
class Solution(object):
	def inorderTraversal(self, root):
		L = []
		node = root
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
					node = node.left
				else:
					L.append(node.val)
					pre.right = None
					node = node.right
		return L
