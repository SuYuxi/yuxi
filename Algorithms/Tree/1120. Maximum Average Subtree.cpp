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
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return maxAve;
    }

private:
    double maxAve = INT_MIN;
    pair<double, int> dfs(TreeNode* node) //<sum, nodeCnt>
    {
        if(!node) return make_pair(0, 0);
        auto L = dfs(node->left);
        auto R = dfs(node->right);
        double sum = L.first + R.first + node->val;
        int nodes = L.second + R.second + 1;
        maxAve = max(maxAve, sum / nodes);
        return make_pair(sum, nodes);       
    }
};
