class Solution(object):
	def oddEvenList(self, head):
		if(not head):	
			return
		odd = head
		even = head.next
		even_head = even 	
		while(even and even.next):
			odd.next = even.next
			odd = odd.next
			even.next = odd.next
			even = even.next
		odd.next = even_head
		return head
