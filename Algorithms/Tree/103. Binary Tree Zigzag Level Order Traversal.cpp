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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if(root == nullptr) return res;
		queue<TreeNode*> q;
		TreeNode* node;
		q.emplace(root);
		bool rightToLeft = true;
		while(!q.empty()) {
			int length = q.size();
			vector<int> level(length);
			for(int i = 0; i < length; ++i) {
				node = q.front();
				q.pop();
				int index = rightToLeft ? i : length - 1 - i;
				level[index] = node->val;
				if(node->left) q.emplace(node->left);
				if(node->right) q.emplace(node->right);
			}
			rightToLeft = !rightToLeft;
			res.emplace_back(level);
		}
		return res;
    }
};
