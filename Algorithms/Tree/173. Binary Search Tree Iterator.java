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
class BSTIterator {
    private Stack<TreeNode> stack;
    
    public BSTIterator(TreeNode root) {
        stack = new Stack();
        TreeNode cur = root;
        while(cur != null) {
            stack.push(cur);
            cur = cur.left;
        }
    }
    
    public int next() {
        TreeNode node = stack.pop();
        TreeNode cur = node;
        if(cur.right != null) {
            cur = cur.right;
            while(cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
        }
        return node.val;
    }
    
    public boolean hasNext() {
        return !stack.isEmpty();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
