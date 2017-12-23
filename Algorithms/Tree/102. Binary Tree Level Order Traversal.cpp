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
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if(!root) return res;
		queue<TreeNode*> q;
		q.emplace(root);
		int length;
		TreeNode * node;
		while(!q.empty()) {
			length = q.size();
			vector<int> level;
			for(int i = 0; i < length; ++i) {
				node = q.front();
				q.pop();
				level.emplace_back(node->val);
				if(node->left) q.emplace(node->left);
				if(node->right) q.emplace(node->right);
			}
			res.emplace_back(level);
		}
		return res;
        
    }
};

class Solution {
private:
	vector<vector<int>> res;
public:
	void buildVector(TreeNode *root, int depth) {
		if(root == nullptr) return;
		if(res.size() == depth) res.push_back(vector<int>());
		res[depth].push_back(root->val);
		buildVector(root->left, depth + 1);
		buildVector(root->right, depth + 1);
	}
	
	vector<vector<int>> levelOrder(TreeNode* root) {
		buildVector(root, 0);
		return res;
	}
};
