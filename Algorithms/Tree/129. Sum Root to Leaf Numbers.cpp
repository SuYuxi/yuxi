/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        if(root) dfs(root, 0);
        return sum;
    }
private:
    void dfs(TreeNode* node, int val)
    {
        val = val * 10 + node->val;
        if(node->left) dfs(node->left, val);
        if(node->right) dfs(node->right, val);
        if(!node->left && !node->right) sum += val;
    }
    int sum;
};
