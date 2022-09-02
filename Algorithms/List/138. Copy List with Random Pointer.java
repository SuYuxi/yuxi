/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return null;
        HashMap<Node, Node> hash = new HashMap();
        Node cur = head;
        while(cur != null) {
            hash.put(cur, new Node(cur.val));
            cur = cur.next;
        }
        cur = head;
        while(cur != null) {
            hash.get(cur).next = hash.get(cur.next);
            hash.get(cur).random = hash.get(cur.random);
            cur = cur.next;
        }
        return hash.get(head);
    }
}
