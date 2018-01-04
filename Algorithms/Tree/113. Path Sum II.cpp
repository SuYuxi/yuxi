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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> paths;
		vector<int> path;
		findPaths(root, paths, path, sum);
		return paths;
    }
private:
	void findPaths(TreeNode* root,vector<vector<int>>& paths, vector<int>& path, int sum) {
		if(root == nullptr) return;
		path.push_back(root->val);
		sum -= root->val;
		if(root->left == nullptr && root->right == nullptr && sum == 0) {
			paths.push_back(path);
		}
		findPaths(root->left, paths, path, sum);
		findPaths(root->right, paths, path, sum);
		path.pop_back();
		return;
	}
};
