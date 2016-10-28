#iterative
class Solution(object):
    def deleteDuplicates(self, head):
        s = set()
        p = head
        q = None
        while(p):
            if p.val in s:
                q.next = p.next
                p = p.next
            else:
                s.add(p.val)
                q = p
                p = p.next
        return head

#recursive
class Solution(object):
    def deleteDuplicates(self, head):
        s = set()
        def delete(node, pre = None):
            if(not node):
                return
            if(node.val in s):
                pre.next = node.next
                node = node.next
            else:
                s.add(node.val)
                pre = node
                node = node.next
            return delete(node, pre)
        delete(head)    
        return head
