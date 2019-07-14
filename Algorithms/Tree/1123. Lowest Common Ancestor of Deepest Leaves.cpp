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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
private:
    pair<int, TreeNode*> dfs(TreeNode* node) //<depth, node>
    {
		if(!node) return {0, nullptr};
		auto L = dfs(node->left);
		auto R = dfs(node->right);
		if(L.first > R.first)
		{
			node = L.second;	
		}
		else if(L.first < R.first)
		{
			node = R.second;
		}
		return {max(L.first, R.first) + 1, node};
    }
};
