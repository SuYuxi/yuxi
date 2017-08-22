# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
		if(not head):
			return list()
		length = 0
		p = head
		while(p):
			p = p.next
			length += 1
		k %= length
		fast, slow = head, head
		for _ in range(k):
			fast = fast.next
		while(fast.next):
			fast = fast.next
			slow = slow.next
		fast.next = head
		head = slow.next
		slow.next = None
		return head
