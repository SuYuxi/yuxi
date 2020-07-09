/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        maxWidth = 0;
        dfs(root, 0, 0);
        return maxWidth;
    }
    void dfs(TreeNode* node, int depth, unsigned long order) {
        if(left.size() == depth) left.emplace_back(order);
        else left[depth] = min(left[depth], order);
        maxWidth = max(maxWidth, order - left[depth] + 1);
        if(node->left) dfs(node->left, depth + 1, 2 * order);
        if(node->right) dfs(node->right, depth + 1, 2 * order + 1);
    }
    
private:
    vector<unsigned long> left;
    unsigned long maxWidth;
};
