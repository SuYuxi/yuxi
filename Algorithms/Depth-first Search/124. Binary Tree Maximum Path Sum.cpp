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
	int maxValue = INT_MIN;

    int maxPathSum(TreeNode * root)
	{
		DFS(root);
		return maxValue;
    }

private:
	int DFS(TreeNode * node)
	{
		if(node == nullptr) return 0;
		int left = max(0, DFS(node->left));
		int right = max(0, DFS(node->right));
		maxValue = max(maxValue, left + node->val + right);
		return node->val + max(left, right);
	}
};
