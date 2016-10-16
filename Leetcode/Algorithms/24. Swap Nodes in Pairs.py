#recursive
class Solution(object):
    def swapPairs(self, head):
        if(head and head.next):
            q = head.next
            head.next = self.swapPairs(q.next)
            q.next = head
            return q
        return head or None

#iterative
class Solution(object):
    def swapPairs(self, head):
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        while(pre.next and pre.next.next):
            p = pre.next
            q = p.next
            pre.next, p.next, q.next = q, q.next, p
            pre = p
        return dummy.next
