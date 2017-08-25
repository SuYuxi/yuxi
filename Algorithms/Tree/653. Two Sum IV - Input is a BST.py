# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution(object):
    def findTarget(self, root, k):
		stack = list()
		sortedList = list()
		node = root
		while(node or stack):
			while(node):
				stack.append(node)
				node = node.left
			node = stack.pop()
			sortedList.append(node.val)
			node = node.right
		left, right = 0, len(sortedList) - 1
		while(left < right):
			Sum = sortedList[left] + sortedList[right]
			if(Sum == k):
				return True
			elif(Sum < k):
				left += 1
			else:
				right -= 1
		return False

class Solution(object):
    def findTarget(self, root, k):
		def traverse(node, k):
			if(not node):
				return False
			if(k - node.val in S):
				return True
			S.add(node.val)
			return traverse(node.left, k) or traverse(node.right, k)
		S = set()
		return traverse(root, k)
