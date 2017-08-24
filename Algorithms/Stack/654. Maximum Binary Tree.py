# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
		stack = list()
		for num in nums:
			cur = TreeNode(num)
			while(stack and stack[-1].val < num):
				cur.left = stack[-1]
				stack.pop()
			if(stack):
				stack[-1].right = cur
			stack.append(cur)
		return stack[0] if stack else None
