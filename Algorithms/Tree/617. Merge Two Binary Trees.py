# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
	def mergeTrees(self, t1, t2):
		if(not t1):
			return t2
		if(not t2):
			return t1
		t1.val += t2.val
		t1.left = self.mergeTrees(t1.left, t2.left)
		t1.right = self.mergeTrees(t1.right, t2.right)
		return t1


class Solution(object):
	def mergeTrees(self, t1, t2):
		if(not t1):
			return t2
		if(not t2):
			return t1
		stack = list()
		stack.append((t1, t2))
		while(stack):
			cur = stack.pop()	
			cur[0].val += cur[1].val
			if(not cur[0].right):
				if(cur[1].right):
					cur[0].right = cur[1].right
			elif(cur[1].right):
				stack.append((cur[0].right, cur[1].right))
			if(not cur[0].left):
				if(cur[1].left):
					cur[0].left = cur[1].left
			elif(cur[1].left):
				stack.append((cur[0].left, cur[1].left))
		return t1
