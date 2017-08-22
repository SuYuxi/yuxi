# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def reverseKGroup(self, head, k):
		def reverse(dummy, end):
			newEnd = cur = dummy.next
			pre = end.next
			while(cur != end):
				pre, cur.next, cur = cur, pre, cur.next
			cur.next = pre
			dummy.next = cur 
			return newEnd

		dummy = ListNode(None)
		dummy.next = head
		header = dummy
		pointer = head
		num = 0
		while(pointer):
			num += 1	
			if(num == k):
				num = 0
				header = reverse(header, pointer)
				pointer = header.next	
			else:
				pointer = pointer.next	
		return dummy.next
