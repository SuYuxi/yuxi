/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
		if(root == nullptr) return 0;
		if(root->left == nullptr) return 1 + minDepth(root->right);
		if(root->right == nullptr) return 1 + minDepth(root->left);
		return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
		if(root == nullptr) return 0;
		std::queue<TreeNode*> nodeQueue;
		nodeQueue.push(root);
		int depth = 0;
		while(!nodeQueue.empty()) {
			depth += 1;
			int length = nodeQueue.size();
			for(int i = 0; i < length; i += 1) {
				TreeNode* node = nodeQueue.front();
				if(node->left != nullptr) nodeQueue.push(node->left);
				if(node->right != nullptr) nodeQueue.push(node->right);
				if(node->left == nullptr && node->right == nullptr) return depth;
				nodeQueue.pop();
			}
		}
	}
};
