/**wq
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//recursive
class Solution {
public:
    void recoverTree(TreeNode* root) {
		traversal(root);
		if(first == nullptr || second == nullptr) return;
		swap(first->val, second->val);
		return;
    }
private:
	TreeNode* first = nullptr;
	TreeNode* second = nullptr;
	TreeNode* pre = new TreeNode(~((unsigned)~0>>1)^1); //INT_MIN INT_MIN:(unsigned)-1>>1
	void traversal(TreeNode*& node) {
		if(node == nullptr) return;
		traversal(node->left);	
		if(pre->val >= node->val) {
			if(first == nullptr) first = pre;
			second = node;
		}
		pre = node;
		traversal(node->right);
	}

	template<class T>
	void swap(T& a, T& b) {
		T temp(std::move(a));
		a = std::move(b);
		b = std::move(temp);
		return;
	}
};

//iterative
class Solution {
public:
    void recoverTree(TreeNode* root) {
		traversal(root);
		if(first == nullptr || second == nullptr) return;
		swap(first->val, second->val);
		return;
    }
private:
	TreeNode* first = nullptr;
	TreeNode* second = nullptr;
	
	void traversal(TreeNode* node) {
		stack<TreeNode*> nodeStack;
		TreeNode* pre = new TreeNode(~((unsigned)~0>>1)^1); //INT_MIN INT_MIN:(unsigned)-1>>1
		while(!nodeStack.empty() || node != nullptr) {
			if(node != nullptr) {
				nodeStack.push(node);
				node = node->left;
			}
			else {
				node = nodeStack.top();
				nodeStack.pop();
				if(node->val <= pre->val) {
					if(first == nullptr) first = pre;
					second = node;
				}
				pre = node;
				node = node->right;
			}
		}
	}

	template<class T>
	void swap(T& a, T& b) {
		T temp(std::move(a));
		a = std::move(b);
		b = std::move(temp);
		return;
	}
};

//morris traversal
class Solution {
public:
    void recoverTree(TreeNode* root) {
		traversal(root);
		if(first == nullptr || second == nullptr) return;
		swap(first->val, second->val);
		return;
	}

private:
	TreeNode* first = nullptr;
	TreeNode* second = nullptr;
	void traversal(TreeNode * root) {
		TreeNode* curr = root,* prec = nullptr,* prev = nullptr;
		while(curr != nullptr) {
			if(prev != nullptr && curr->val <= prev->val) {
				if(first == nullptr) first = prev;
				second = curr;
			}
			if(curr->left == nullptr) {
				prev = curr;
				curr = curr->right;
			}
			else {
				prec = curr->left;
				while(prec->right != nullptr && prec->right != curr) {
					prec = prec->right;
				}
				if(prec->right == nullptr) {
					prec->right = curr;
					curr = curr->left;
				}
				else {
					prec->right = nullptr;
					prev = curr;
					curr = curr->right;
				}
			}
		}
	}

	template<class T>
	void swap(T& a, T& b) {
		T temp(std::move(a));
		a = std::move(b);
		b = std::move(temp);
		return;
	}
};
