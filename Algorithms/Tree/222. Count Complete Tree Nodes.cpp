/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//recursive
class Solution {
public:
    int countNodes(TreeNode* root) {
		int cnt = 0;
		inorderTraverse(root, cnt);
		return cnt;
    }
private:
	void inorderTraverse(TreeNode* node, int& cnt) {
		if(node == nullptr) return;
		cnt++;
		inorderTraverse(node->left, cnt);
		inorderTraverse(node->right, cnt);
	}
};

//iterative
class Solution {
public:
    int countNodes(TreeNode* root) {
		if(root == nullptr) return 0;
		int cnt = 0;
		vector<TreeNode*> stack;
		TreeNode* node = root;
		while(node != nullptr || !stack.empty())
		{
			if(node == nullptr)
			{
				node = stack.back();
				stack.pop_back();
			}
			cnt++;
			if(node->right != nullptr) stack.emplace_back(node->right);
			node = node->left;
		}
		return cnt;
	}
};
