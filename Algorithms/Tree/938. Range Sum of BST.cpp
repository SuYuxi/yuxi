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
    int rangeSumBST(TreeNode* root, const int& L, const int& R) {
		if(root == nullptr) return 0;
		int sum = 0, cur = root->val;
		if(cur >= L && cur <= R)
		{
			sum += cur;
			sum += rangeSumBST(root->left, L, R);
			sum += rangeSumBST(root->right, L, R);
		}
		else if(cur < L)
		{
			sum += rangeSumBST(root->right, L, R);
		}
		else
		{
			sum += rangeSumBST(root->left, L, R);
		}
		return sum;
    }
};
