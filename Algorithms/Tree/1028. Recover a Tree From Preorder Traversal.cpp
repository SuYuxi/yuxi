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
    TreeNode* recoverFromPreorder(string S) {
		vector<pair<int, int>> tree;
		int i = 0;
		while(i < S.size())
		{
			int depth = 0;
			while(i < S.size() && S[i] == '-')
			{
				depth++;
				i++;
			}
			int num = 0;
			while(i < S.size() && S[i] != '-')
			{
				num *= 10;
				num += S[i] - '0';		
				i++;
			}
			tree.emplace_back(make_pair(depth, num));
		}
		TreeNode* root = new TreeNode(0);
		int inx = 0;
		dfs(root, 0, inx, tree);
		return root;
    }
	void dfs(TreeNode* node, int depth, int& inx, vector<pair<int, int>>& tree) {
		node->val = tree[inx].second;
		inx++;
		if(inx < tree.size() && depth + 1 == tree[inx].first)
		{
			node->left = new TreeNode(0);	
			dfs(node->left, depth + 1, inx, tree);
		}
		if(inx < tree.size() && depth + 1 == tree[inx].first)
		{
			node->right= new TreeNode(0);	
			dfs(node->right, depth + 1, inx, tree);
		}
	}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
		vector<TreeNode*> stack;
		for(int i = 0, depth, val; i < S.size();)
		{
			depth = 0;
			while(i < S.size() && S[i] == '-')
			{
				depth++;
				i++;
			}
			val = 0;
			while(i < S.size() && S[i] != '-')
			{
				val *= 10;
				val += S[i] - '0';		
				i++;
			}
			TreeNode* node = new TreeNode(val);
			while(stack.size() > depth) stack.pop_back();
			if(!stack.empty())
			{
				if(!stack.back()->left) stack.back()->left = node;
				else stack.back()->right = node;
			}
			stack.emplace_back(node);
		}
		return stack.front();
	}
};
