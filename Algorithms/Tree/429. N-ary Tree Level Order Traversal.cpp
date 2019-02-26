/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> res;
		queue<Node*> que;
		if(root != nullptr)
		{
			que.emplace(root);
		}
		while(!que.empty())
		{
			int num = que.size();
			vector<int> level;
			for(int i = 0; i < num; i += 1)
			{
				Node* node = que.front();
				level.emplace_back(node->val);
				que.pop();
				for(Node*& child : node->children)
				{
					que.emplace(child);
				}
			}
			res.emplace_back(level);
		}
		return res;
    }
};
