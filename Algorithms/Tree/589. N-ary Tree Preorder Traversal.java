/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
//Recursive
class Solution {
    public List<Integer> list = new ArrayList<>();
    public List<Integer> preorder(Node root) {
        if(root == null) return list;
        list.add(root.val);
        
        for(Node child : root.children) {
            preorder(child);
        }
        return list;
    }
}

//Iterative
class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> list = new ArrayList<>();
        if(root == null) return list;
        
        Stack<Node> stack = new Stack<>();
        stack.add(root);
        
        while(!stack.empty()) {
            Node node = stack.pop();
            list.add(node.val);
            for(int i = node.children.size() - 1; i >= 0; --i) {
                stack.add(node.children.get(i));
            }
        }

        return list;
    }
}
