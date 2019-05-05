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
    TreeNode* bstToGst(TreeNode* root) {
		if(!root) return root;
		bstToGst(root->right);
		sum += root->val;
		root->val = sum;
		bstToGst(root->left);
		return root;
    }
private:
	int sum = 0;
};
