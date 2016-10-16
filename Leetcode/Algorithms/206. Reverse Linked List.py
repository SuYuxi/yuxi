#iterative
class Solution(object):
    def reverseList(self, head):
        if(not head):
            return head
        p = head.next
        head.next = None
        q = head
        while(p):
            temp = p.next
            p.next = q
            q = p
            p = temp
        return q

#recursive
class Solution(object):
    def reverseList(self, head):
        def rev(node,pre=None):
            if(not node):
                return pre
            temp = node.next
            node.next = pre
            return rev(temp, node)
        return rev(head)
