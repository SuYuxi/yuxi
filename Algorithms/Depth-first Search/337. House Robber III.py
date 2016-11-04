#hashmap
class Solution(object):
	def rob(self, root, hashmap = {}):
		if(not root):
			return 0	
		if(root in hashmap):
			return hashmap[root]
		amount = 0	
		if(root.left):
			amount += self.rob(root.left.left, hashmap) + self.rob(root.left.right, hashmap)
		if(root.right):
			amount += self.rob(root.right.left, hashmap) + self.rob(root.right.right, hashmap)
		amount = max(root.val + amount, self.rob(root.left, hashmap) + self.rob(root.right, hashmap))
		hashmap[root] = amount
		return amount

#better solution without hashmap
class Solution(object):
	def rob(self, root):
		def subrob(node):
			if(not node):
				return [0, 0]
			res = [0, 0]
			left = subrob(node.left)
			right = subrob(node.right)
			res[0] = max(left) + max(right)
			res[1] = node.val + left[0] + right[0]
			return  res
		return max(subrob(root))
