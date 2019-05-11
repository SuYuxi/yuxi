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
    int longestUnivaluePath(TreeNode* root) {
		ans = 0;
		dfs(root);
		return ans;
    }

private:
	int ans;
	int dfs(TreeNode* node) {
		if(!node) return 0;
		int leftDepth = dfs(node->left);
		int rightDepth = dfs(node->right);
		int left = 0, right = 0;

		if(node->left && node->left->val == node->val)
		{
			left += 1 + leftDepth;
		}
		if(node->right && node->right->val == node->val)
		{
			right += 1 + rightDepth;
		}
		ans = max(ans, left + right);
		return max(left, right);
	}
};
