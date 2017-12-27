/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#recursion
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int i = inorder.size() - 1, p = postorder.size() - 1;
		return helper(inorder, postorder, i, p, nullptr);
	}
	
private:
	TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int& i, int& p, TreeNode* stop) {
		if(i >= 0 && (stop == nullptr || inorder[i] != stop->val)) {
			TreeNode * root = new TreeNode(postorder[p--]);
			root->right = helper(inorder, postorder, i, p, root);
			i--;
			root->left = helper(inorder, postorder, i, p, stop);
			return root;
		}
		else {
			return nullptr;
		}
	}
};

#iteractive
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if(inorder.empty()) return nullptr;
		int i = inorder.size() - 1, p = postorder.size() - 1;
		TreeNode* root = new TreeNode(postorder[p--]);
		stack<TreeNode*> nodeStack;
		nodeStack.push(root);
		while(i >= 0) {
			TreeNode* node = nodeStack.top();
			if(node->val != inorder[i]) {
				node->right = new TreeNode(postorder[p--]);
				nodeStack.push(node->right);
			}
			else {
				while(!nodeStack.empty() && nodeStack.top()->val == inorder[i]) {
					node = nodeStack.top();
					nodeStack.pop();
					i--;
				}
				if(i >= 0) {
					node->left = new TreeNode(postorder[p--]);
					nodeStack.push(node->left);
				}
			}
		}
		return root;
    }
};
