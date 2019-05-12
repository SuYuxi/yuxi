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
    ListNode* removeElements(ListNode* head, int val) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;

		ListNode *p1 = head, *p2 = dummy;
		while(p1)
		{
			if(p1->val != val)
			{
				p2 = p1;
			}
			else
			{
				p2->next = p1->next;
			}
			p1 = p1->next;
		}
		return dummy->next;
    }
};
