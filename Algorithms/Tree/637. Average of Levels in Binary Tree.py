# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution(object):
	def averageOfLevels(self, root):
		res = list()
		if(not root):
			return res
		stack = list()
		stack.append(root)
		while(stack):
			temp = list()		
			Sum = 0
			count = 0
			while(stack):
				node = stack.pop()
				Sum += node.val
				count += 1
				if(node.left):
					temp.append(node.left)
				if(node.right):
					temp.append(node.right)
			stack = temp
			res.append(Sum / count)
		return res
