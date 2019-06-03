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
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        ans = 0;
        dfs(root, root->val, root->val);
        return ans;
    }

private:
    int ans;
    void dfs(TreeNode* node, int Max, int Min) {
        if(!node) return;
        ans = max(ans, abs(node->val - Max));
        ans = max(ans, abs(Min - node->val));
        Max = max(Max, node->val);
        Min = min(Min, node->val);
        dfs(node->left, Max, Min);
        dfs(node->right, Max, Min);
    }
};

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

private:
    int dfs(TreeNode* node, int Max, int Min) {
        if(!node) return Max - Min;
        Max = max(Max, node->val);
        Min = min(Min, node->val);
        return max(dfs(node->left, Max, Min), dfs(node->right, Max, Min));
    }
};
