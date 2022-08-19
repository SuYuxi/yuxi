/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSubPath(ListNode head, TreeNode root) {
        if(head == null) return true;
        if(root == null) return false;
        return (dfs(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right));
    }
    
    public boolean dfs(ListNode head, TreeNode root) {
        if(head == null) return true;
        if(root == null) return false;
        return head.val == root.val && (dfs(head.next, root.left) || dfs(head.next, root.right));
    }
}

//KMP
class Solution {
    public boolean isSubPath(ListNode head, TreeNode root) {
        List<Integer> A = new ArrayList(), dp = new ArrayList();
        A.add(head.val);
        dp.add(0);
        int i = 0;
        head = head.next;
        while (head != null) {
            while (i > 0 && head.val != A.get(i))
                i = dp.get(i - 1);
            if (head.val == A.get(i)) ++i;
            A.add(head.val);
            dp.add(i);
            head = head.next;
        }
        return dfs(root, 0, A, dp);
    }

    private boolean dfs(TreeNode root, int i, List<Integer> A, List<Integer> dp) {
        if (root == null) return false;
        while (i > 0 && root.val != A.get(i))
            i = dp.get(i - 1);
        if (root.val == A.get(i)) ++i;
        return i == dp.size() || dfs(root.left, i, A, dp) || dfs(root.right, i, A, dp);
    }
}
