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
    vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if(root != nullptr)
		{
			DFS(root, string(), res);
		}
		return res;
    }

	void DFS(TreeNode* node, string path, vector<string> &res) {
		path += "->" + to_string(node->val);
		bool isLeaf = true;
		if(node->left != nullptr)
		{
			DFS(node->left, path, res);
			isLeaf = false;
		}
		if(node->right != nullptr)
		{
			DFS(node->right, path, res);
			isLeaf = false;
		}
		if(isLeaf)
		{
			path.erase(0, 2);
			res.emplace_back(path);
			return;
		}
		return;
	}
};
