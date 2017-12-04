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
    bool isBalanced(TreeNode* root) {
		return dfs(root) != -1;
    }
private:
	int dfs(TreeNode* node) {
		if(node == NULL) return 0;
		int leftHeight = dfs(node->left);
		if(leftHeight == -1) return -1;
		int rightHeight = dfs(node->right);
		if(rightHeight == -1) return -1;
		if(abs(leftHeight - rightHeight) > 1) return -1;
		return max(leftHeight, rightHeight) + 1;
	}
};
