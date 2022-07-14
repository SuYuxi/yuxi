/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    map<int, vector<TreeNode*>> dp;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(dp.count(n) == 0) {
            vector<TreeNode*> ans;
            if(n == 1) {
                ans.emplace_back(new TreeNode(0));
            }
            else if(n % 2 == 1) {
                for(int x = 0; x < n; ++x) {
                    for(TreeNode* left : allPossibleFBT(x)) {
                        for(TreeNode* right : allPossibleFBT(n - 1 - x)) {
                            TreeNode* root = new TreeNode(0);
                            root->left = left;
                            root->right = right;
                            ans.emplace_back(root);
                        }
                    }
                }    
            }
            dp[n] = ans;
        }
        return dp[n];
    }
};
