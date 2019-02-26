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
    int pathSum(TreeNode* root, int sum) {
		int count = 0;
		dfs(root, sum, count);
		return count;
    }

private:
	void dfs(TreeNode* node, int sum, int& count)
	{
		if(node == nullptr) return;
		subPathSum(node, sum, count);
		dfs(node->left, sum, count);
		dfs(node->right, sum, count);
	}

	void subPathSum(TreeNode* node, int sum, int& count)
	{
		if(node == nullptr) return; 
		if(sum == node->val) count += 1;
		subPathSum(node->left, sum - node->val, count);
		subPathSum(node->right, sum - node->val, count);
	}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
		int result = 0;
		map<int, int> dict;
		dict.insert(make_pair(0, 1));
		dfs(root, sum, 0, result, dict);
		return result;
    }

private:
	void dfs(TreeNode* node, int target, int curSum, int& result, map<int, int>& dict)
	{
		if(node == nullptr) return;
		curSum += node->val;
		int oldSum = curSum - target;
		if(dict.count(oldSum) != 0)
		{
			result += dict[oldSum];
		}
		if(dict.count(curSum) == 0)
		{
			dict[curSum] = 1;
		}
		else
		{
			dict[curSum] += 1;
		}
		dfs(node->left, target, curSum, result, dict);
		dfs(node->right, target, curSum, result, dict);
		dict[curSum] -= 1;
	}
};
