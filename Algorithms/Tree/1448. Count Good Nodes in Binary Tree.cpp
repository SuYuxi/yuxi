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
    int goodNodes(TreeNode* root, int maximum = INT_MIN) {
        return root == nullptr ? 0 : (root->val >= maximum)
            + goodNodes(root->left, max(maximum, root->val))
            + goodNodes(root->right, max(maximum, root->val));
    }
};
