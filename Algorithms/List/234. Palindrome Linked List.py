# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
		slow, fast, pre = head, head, None
		while(fast and fast.next):
			fast = fast.next.next
			pre, pre.next, slow = slow, pre, slow.next
		tail = slow.next if fast else slow
		node = pre
		pre = slow
		isPalin = True
		while(node):
			if(node.val != tail.val):
				isPalin = False
			tail = tail.next
			pre, pre.next, node = node, pre, node.next
		return isPalin
