/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#recursive
class Solution {
public:
    void flatten(TreeNode* root) {
		if(root == nullptr) return;
		flatten(root->right);
		flatten(root->left);
		root->left = nullptr;
		root->right = pre;
		pre = root;
    }
private:
	TreeNode* pre = nullptr;
};

class Solution {
public:
    void flatten(TreeNode* root) {
		TreeNode* cur = root;
		while(cur){
			if(cur->left) {
				TreeNode* runner = cur->left;
				while(runner->right) {
					runner = runner->right;
				}
				runner->right = cur->right;
				cur->right = cur->left;
				cur->left = nullptr;
			}
			cur = cur->right;
		}
	}
};
