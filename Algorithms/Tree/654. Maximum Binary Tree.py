# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
		def recursive(nums, left, right):
			if(left == right):
				return None
			maximum = (left, nums[left])
			for inx in range(left, right):
				if(nums[inx] > maximum[1]):
					maximum = (inx, nums[inx])
			root = TreeNode(maximum[1])
			root.left = recursive(nums, left, maximum[0])
			root.right = recursive(nums, maximum[0] + 1, right)
			return root
		return recursive(nums, 0, len(nums))
