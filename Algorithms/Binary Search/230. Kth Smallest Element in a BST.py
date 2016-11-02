#Binary Search
class Solution(object):
	def kthSmallest(self, root, k):
		def count(root):
			return 1 + count(root.left) + count(root.right) if root else 0 
		
		if(not root):
			return None
		num = count(root.left)
		if(num > k - 1):
			return self.kthSmallest(root.left, k)
		elif(num < k - 1):
			return self.kthSmallest(root.right, k - num - 1)
		else:
			return root.val


#python generator
class Solution(object):
	def kthSmallest(self, root, k):
		def inorder(node):
			if(node):
				for val in inorder(node.left):
					yield val	
				yield node.val
				for val in inorder(node.right):
					yield val	
					
		for val in inorder(root):
			if (k == 1):
				return val
			else:
				k -= 1
#recursive
class Solution(object):
	def kthSmallest(self, root, k):
		def inorder(node, k):
			if(node):
				ans = inorder(node.left, k)
				if(ans != None):
					return ans
				if (k[0] == 1):
					return node.val
				else:
					k[0] -= 1
				ans = inorder(node.right, k)
				if(ans != None):
					return ans
				return None
		k = [k]
		return inorder(root, k)

#iterative
class Solution(object):
	def kthSmallest(self, root, k):
		stack = []
		node = root
		while(node or len(stack)):
			if(node):
				stack.append(node)
				node = node.left
			else:
				node = stack.pop()
				k -= 1
				if(k == 0):
					return node.val
				node = node.right
