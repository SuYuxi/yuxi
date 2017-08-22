# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def removeNthFromEnd(self, head, n):
		dummy = ListNode(None)
		dummy.next = head
		first = dummy
		second = dummy
		for i in range(n):
			first = first.next
		while(first.next):
			first = first.next
			second = second.next
		second.next = second.next.next
		return dummy.next
