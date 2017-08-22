# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findFrequentTreeSum(self, root):
		def postorder(node):
			if(not node):
				return 0
			treesum = postorder(node.left) + postorder(node.right) + node.val
			values[treesum] = values.setdefault(treesum, 0) + 1
			return treesum 
		values = dict()
		postorder(root)
		maxcnt = -1
		res = list()
		for key, val in values.items():
			if(val > maxcnt):
				maxcnt = val
				res = [key]
			elif(val == maxcnt):
				res.append(key)
		return res
