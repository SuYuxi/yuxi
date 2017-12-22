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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if(!headA || !headB) return NULL;
		ListNode *A = headA, *B = headB;
		while(A && B) {
			A = A->next;
			B = B->next;
		}
		if(!A) A = headB;
		if(!B) B = headA;
		while(A && B) {
			A = A->next;
			B = B->next;
		}
		if(!A) A = headB;
		if(!B) B = headA;
		while(A && B) {
			if(A == B) return A;
			A = A->next;
			B = B->next;
		}
		return NULL;
    }
};
