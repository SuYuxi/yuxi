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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 0);
    }
    
    bool dfs(TreeNode* node, vector<int>& arr, int inx) {
        if(!node || (inx == arr.size()) || node->val != arr[inx]) return false;
        if(inx == arr.size() - 1 && !node->left && !node->right) return true;
        return dfs(node->left, arr, inx + 1) || dfs(node->right, arr, inx + 1);
    }
};
