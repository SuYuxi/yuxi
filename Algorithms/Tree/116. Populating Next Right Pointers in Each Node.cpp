/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
		if(root == nullptr) return;
		queue<TreeLinkNode*> que;
		TreeLinkNode *node;
		que.push(root);
		int count = 0;
		int length = que.size();
		while(!que.empty()){
			++count;
			node = que.front();
			que.pop();
			if(node->left) que.push(node->left);
			if(node->right) que.push(node->right);
			if(count == length) {
				length = que.size();	
				count = 0;
			}
			else {
				node->next = que.front();
			}
		}
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
		if(root == nullptr) return;
		if(root->left) root->left->next = root->right;
		if(root->right && root->next) root->right->next = root->next->left;
		connect(root->left);
		connect(root->right);
	}
};
