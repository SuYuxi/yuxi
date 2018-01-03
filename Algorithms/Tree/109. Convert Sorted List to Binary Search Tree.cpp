/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
		int count = 0;
		ListNode* runner = head;
		node = head;
		while(runner) {
			++count;
			runner = runner->next;
		}
		return preOrderTraversalBuilder(0, count - 1);
    }
private:
	ListNode* node = nullptr;
	TreeNode* preOrderTraversalBuilder(int start, int end) {
		if(start > end) {
			return nullptr;
		}
		TreeNode* root = new TreeNode(NULL);
		root->left = preOrderTraversalBuilder(start, ceil(float(start + end) / 2 - 1));
		root->val = node->val;
		node = node->next;
		root->right = preOrderTraversalBuilder(ceil(float(start + end) / 2 + 1), end);
		return root;
	}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
		if(head == nullptr) return nullptr;
		return toBST(head, nullptr);
	}
private:
	TreeNode* toBST(ListNode* head, ListNode* end) {
		if(head == end) return nullptr;
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast != end && fast->next != end) {
			fast = fast->next->next;
			slow = slow->next;
		}
		TreeNode* node = new TreeNode(slow->val);
		node->left = toBST(head, slow);
		node->right = toBST(slow->next, end);
		return node;
	}
};
