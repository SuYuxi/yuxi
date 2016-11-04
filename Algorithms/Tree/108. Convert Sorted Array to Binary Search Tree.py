class Solution(object):
	def sortedArrayToBST(self, nums):
		def BST(nums):
			if(not nums):
				return None 
			length = len(nums)
			mid = (length - 1) >> 1
			node = TreeNode(nums[mid])
			node.val = nums[mid]
			node.left = BST(nums[0:mid])
			if(mid < length - 1):
				node.right = BST(nums[mid + 1:length])
			return node
		return BST(nums)
