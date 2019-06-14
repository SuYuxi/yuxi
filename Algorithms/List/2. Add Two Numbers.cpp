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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        while(carry != 0 || l1 || l2)
        {
            if(l1)
            {
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                carry += l2->val;
                l2 = l2->next;
            }
            node->next = new ListNode(carry % 10);
            node = node->next;
            carry /= 10;
        }
        return dummy->next;
    }
};
