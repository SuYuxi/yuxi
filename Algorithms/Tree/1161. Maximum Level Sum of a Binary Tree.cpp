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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN, curSum = 0;
        int level = 0, curLevel = 0;
        deque<TreeNode*> queue = {root};
        while(!queue.empty())
        {
            curSum = 0;
			curLevel++;
			int n = queue.size();
			for(int i = 0; i < n; i++)
            {
                TreeNode* node = queue.front();
				queue.pop_front();
				curSum += node->val;
                if(node->left) queue.emplace_back(node->left);
                if(node->right) queue.emplace_back(node->right);
            }
            if(curSum > maxSum)
            {
                maxSum = curSum;
                level = curLevel;
            }
        }
        return level;
    }
};
