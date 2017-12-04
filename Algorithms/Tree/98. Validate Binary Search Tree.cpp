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
		bool isValidBST(TreeNode* root) {
			return isValidBST(root, nullptr, nullptr);
		}
	private:
		bool isValidBST(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
			if(node == nullptr) return true;
			if(minNode && node->val <= minNode->val || maxNode && node->val >= maxNode->val) return false;
			return isValidBST(node->left, minNode, node) && isValidBST(node->right, node, maxNode);
		}
};

#include <stack>
class Solution {
	public:
		bool isValidBST(TreeNode* root) {
			if(root == nullptr) return true;
			stack<TreeNode*> nodeStack;
			TreeNode* pre = nullptr;
			while(root != nullptr || !nodeStack.empty()) {
				while(root != nullptr){
					nodeStack.push(root);
					root = root->left;
				}
				root = nodeStack.top();
				nodeStack.pop();
				if(pre != nullptr && root->val <= pre->val) return false;
				pre = root;
				root = root->right;
			}
			return true;
		}
};
