/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int MOD = 1e9 + 7;
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
		res = 0;
		dfs(root, 0);
		return res;
    }

private:
	int res;
	void dfs(TreeNode* node, int sum)
	{
		sum = ((sum << 1) + node->val) % MOD;
		if(node->left == nullptr && node-> right == nullptr)
		{
			res = (res + sum) % MOD;
			return;
		}
		if(node->left != nullptr)
		{
			dfs(node->left, sum);
		}
		if(node->right != nullptr)
		{
			dfs(node->right, sum);
		}
	}
};
