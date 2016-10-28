#recursive
class Solution(object):
	def postorderTraversal(self, root):
		def traverse(node):
			if(node):
				traverse(node.left)
				traverse(node.right)
				L.append(node.val)
			return
		L = []
		traverse(root)
		return L

#iterative
class Solution(object):
	def postorderTraversal(self, root):
		L = []
		stack = []
		node = root
		while(node or len(stack)):
			if(node):
				L.append(node.val)
				stack.append(node.left)
				node = node.right
			else:
				node = stack.pop()
		return L[::-1]

#morris traversal
class Solution(object):
	def postorderTraversal(self, root):
		dummy = TreeNode(0)
		dummy.left = root
		node = dummy
		L = []
		while(node):
			if(not node.left):
				node = node.right
			else:
				pre = node.left
				while(pre.right and pre.right != node):
					pre = pre.right
				if(not pre.right):
					pre.right = node
					node = node.left
				else:
					pre.right = None
					temp = []
					pointer = node.left
					while(pointer != pre):
						temp.append(pointer.val)
						pointer = pointer.right
					temp.append(pointer.val)
					L += temp[::-1]
					node = node.right
		return L
