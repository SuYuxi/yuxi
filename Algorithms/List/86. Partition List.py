# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def partition(self, head, x):
		head1, head2 = ListNode(None), ListNode(None)
		p1, p2 = head1, head2
		while(head):
			if(head.val < x):
				p1.next = head
				p1 = p1.next
			else:
				p2.next = head
				p2 = p2.next
			head = head.next
		p2.next = None
		p1.next = head2.next
		return head1.next
