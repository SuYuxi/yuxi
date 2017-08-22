# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
		dummy = ListNode(None)
		dummy.next = head
		pre = dummy
		p, q = head, head
		while(p):
			while(q and p.val == q.val):
				q = q.next
			if(p.next != q):
				pre.next = q
			else:
				pre = p
			p = q
		return dummy.next

class Solution(object):
    def deleteDuplicates(self, head):
		dummy = ListNode(None)
		dummy.next = head
		pre = dummy
		cur = head
		while(cur):
			while(cur.next and cur.val == cur.next.val):
				cur = cur.next
			if(pre.next != cur):
				pre.next = cur.next
			else:
				pre = pre.next
			cur = cur.next
		return dummy.next
