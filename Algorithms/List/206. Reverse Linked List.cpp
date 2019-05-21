/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		ListNode* cur = head;
		ListNode* prev = nullptr;
		while(cur != nullptr)
		{
			ListNode* temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}
		return prev;
    }
};

//recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		if(!head || !head->next) return head;
		ListNode* p = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return p;
	}
};
