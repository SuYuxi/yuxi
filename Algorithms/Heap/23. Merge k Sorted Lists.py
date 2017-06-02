# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def mergeKLists(self, lists):
		mergeList = list()
		for head in lists:
			node = head
			while(node):
				mergeList.append(node.val)
				node = node.next
		mergeList = sorted(mergeList)
		dummy = ListNode(None)
		node = dummy
		for val in mergeList:
			node.next = ListNode(val)
			node = node.next
		return dummy.next

class Solution(object):
	def mergeKLists(self, lists):
		def mergeList(left, right):
			dummy = ListNode(None)	
			node = dummy
			while(left and right):
				if(left.val < right.val):
					node.next = ListNode(left.val)
					left = left.next
				else:
					node.next = ListNode(right.val)
					right = right.next
				node = node.next
			node.next = left or right
			return dummy.next

		def recusive(lists):
			if(len(lists) > 2):
				mid = len(lists) // 2
				return(mergeList(recusive(lists[:mid]), recusive(lists[mid:])))
			if(len(lists) == 1):
				return lists[0]
			if(len(lists) == 2):
				return mergeList(lists[0], lists[1])
			
		if(not lists): return None
		return recusive(lists)

import heapq
class Solution(object):
	def mergeKLists(self, lists):
		mergeList = list()
		for head in lists:
			node = head
			while(node):
				heapq.heappush(mergeList, node.val)
				node = node.next
		dummy = ListNode(None)
		node = dummy
		while(mergeList):
			node.next = ListNode(heapq.heappop(mergeList))
			node = node.next
		return dummy.next
