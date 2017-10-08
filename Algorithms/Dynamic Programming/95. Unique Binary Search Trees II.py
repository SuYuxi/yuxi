# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

#divide and conquer
class Solution(object):
    def generateTrees(self, n):
		def generateSubtrees(start, end):
			if((start, end) in self.hashmap):
				return self.hashmap[(start, end)]
			if(start > end):
				return [None]
			res = list()	
			for i in range(start, end+1):
				leftSubtrees = generateSubtrees(start, i-1)
				rightSubtrees = generateSubtrees(i+1, end)
				for leftSubtree in leftSubtrees:
					for rightSubtree in rightSubtrees:
						root = TreeNode(i)
						root.left = leftSubtree
						root.right = rightSubtree
						res.append(root)
			self.hashmap[(start, end)] = res
			return res
		if(not n):	
			return []
		self.hashmap = dict()
		return generateSubtrees(1, n)

#dp
class Solution(object):
    def generateTrees(self, n):
