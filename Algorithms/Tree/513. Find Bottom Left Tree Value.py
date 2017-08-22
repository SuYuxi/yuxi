# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#
# BFS
class Solution(object):
    def findBottomLeftValue(self, root):
		queue = [root]
		for node in queue:
			queue += filter(None, [node.right, node.left])
		return node.val 

from collections import deque
class Solution(object):
    def findBottomLeftValue(self, root):
		queue = deque()
		queue.append(root)
		while(queue):
			node = queue.popleft()
			if(node.right):
				queue.append(node.right)
			if(node.left):
				queue.append(node.left)
		return node.val 
