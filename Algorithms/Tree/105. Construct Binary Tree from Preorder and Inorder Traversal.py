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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int p = 0, i = 0;
		return helper(preorder, inorder, p, i, nullptr);
    }

private:
	TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& p, int& i, TreeNode* stop) {
		if(i < inorder.size() and (stop == nullptr || inorder[i] != stop->val)) {
			TreeNode* root = new TreeNode(preorder[p++]);
			root->left = helper(preorder, inorder, p, i, root); 
			i++;
			root->right = helper(preorder, inorder, p, i, stop); 
			return root;
		}
		else {
			return nullptr;
		}
	}
};

#iterative
class Solution { 
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(inorder.empty()) return nullptr;
		int i = 0, p = 0;
		TreeNode* root = new TreeNode(preorder[p++]);
		stack<TreeNode*> nodeStack;
		nodeStack.push(root);
		while(i < inorder.size()) {
			TreeNode* node = nodeStack.top();
			if(node->val != inorder[i]) {
				node->left = new TreeNode(preorder[p++]);
				nodeStack.push(node->left);
			}
			else {
				while(!nodeStack.empty() && nodeStack.top()->val == inorder[i]) {
					node = nodeStack.top();
					nodeStack.pop();
					i++;
				}
				if(i < inorder.size()) {
					node->right = new TreeNode(preorder[p++]);
					nodeStack.push(node->right);	
				}
			}
		}
		return root;
	}
};
