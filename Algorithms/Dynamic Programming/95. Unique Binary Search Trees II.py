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
		if(n == 0):
			return []
		dp = [[[None] for _ in range(n + 2)] for _ in range(n + 2)]
		for end in range(1, n + 1):
			dp[end][end] = [TreeNode(end)]
			for start in range(end - 1, 0, -1):
				dp[start][end] = list() 
				for root in range(start, end + 1):
					for leftSubtree in dp[start][root - 1]:
						for rightSubtree in dp[root + 1][end]:
							node = TreeNode(root)
							node.left = leftSubtree  
							node.right = rightSubtree 
							dp[start][end].append(node)
		return dp[1][n]
