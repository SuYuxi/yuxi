#iterative
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        p = dummy = ListNode(0)
        while(l1 and l2):
            if(l1.val < l2.val):
                p.next, l1 = l1, l1.next
            else:
                p.next, l2 = l2, l2.next
            p = p.next
        p.next = l1 or l2
        return dummy.next

#recursive
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        if(not l1 or not l2):
            return l1 or l2
        if(l1.val < l2.val):
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2
