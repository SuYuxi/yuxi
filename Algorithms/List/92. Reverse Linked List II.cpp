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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		if(!head) return head;
		ListNode* cur= head, *prev = nullptr;
		int i = 1, j = 1;
		while(i < m)
		{
			prev = cur;
			cur = cur->next;
			i++;
			j++;
		}
		ListNode* tail = cur, *con = prev;
		while(j <= n)
		{
			ListNode* temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
			j++;
		}

		if(con)
		{
			con->next = prev;
		}
		else
		{
			head = prev;
		}
		tail->next = cur;

		return head;
    }
};
