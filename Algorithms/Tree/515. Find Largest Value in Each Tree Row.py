# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution(object):
    def largestValues(self, root):
		if(not root):
			return list()
		res = list()
		layVal = list()
		queue = deque()	
		queue.append(root)
		while(queue):
			queSize = len(queue)
			inx = 0
			layVal = list()
			while(inx < queSize):
				node = queue.popleft()
				layVal.append(node.val)
				if(node.left):
					queue.append(node.left)
				if(node.right):
					queue.append(node.right)
				inx += 1
			res.append(max(layVal))
		return res
