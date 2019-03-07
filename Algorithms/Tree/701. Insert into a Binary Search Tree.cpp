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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
		if(root == nullptr) return new TreeNode(val);
		if(val >= root->val)
		{
			root->right = insertIntoBST(root->right, val);
			return root;
		}
		else
		{
			root->left = insertIntoBST(root->left, val);
			return root;
		}
		return root;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
		TreeNode* node = root, *pre = nullptr;

		while(node != nullptr)
		{
			pre = node;
			if(node->val >= val) node = node->left;
			else node = node->right;
		}
		if(pre->val >= val) pre->left = new TreeNode(val);
		else pre->right = new TreeNode(val);
		return root;
    }
};
