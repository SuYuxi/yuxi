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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        deque<TreeNode*> queue = {root};
        while(!queue.empty())
        {
            int size = queue.size();
            vector<int> layer;
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = queue.front();
                queue.pop_front();
                layer.emplace_back(node->val);
                if(node->left) queue.emplace_back(node->left);
                if(node->right) queue.emplace_back(node->right);
            }
            res.emplace_back(layer);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
