class Solution(object):
    def levelOrderBottom(self, root):
		def search(node, level):
			if(level < len(L)):
				L[level].append(node.val)
			else:
				L.append([node.val])
			if(node.left):
				search(node.left, level + 1) 
			if(node.right):
				search(node.right, level + 1)
			return
		L = []
		if(root):
			search(root, 0)
		return L[::-1]	
