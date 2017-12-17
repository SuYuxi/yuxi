/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
		if(head == nullptr || head->next == nullptr) return; 
		ListNode *p1 = head, *p2 = head->next; 
		while(p2 != nullptr && p2->next != nullptr) {
			p1 = p1->next;
			p2 = p2->next->next;
		}
		ListNode *head2 = p1->next;
		p1->next = nullptr;
		p2 = head2->next;
		head2->next = nullptr;
		while(p2 != nullptr) {
			p1 = p2->next;
			p2->next = head2;
			head2 = p2;
			p2 = p1;
		}
		p1 = head, p2 = head2;
		ListNode *temp = nullptr;
		while(p2 != nullptr) {
			temp = p1->next;	
			p1->next = p2;
			p1 = p2;
			p2 = temp;
		j
	}
};
