/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <queue>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> q; 
		for(ListNode* node : lists)
		{
			if(node) q.emplace(node);
		}
		if(q.empty()) return nullptr;

		ListNode* res = q.top();
		q.pop();
		if(res->next) q.emplace(res->next);
		ListNode* node = res;
		while(!q.empty())
		{
			node->next = q.top();	
			q.pop();
			node = node->next;
			if(node->next) q.emplace(node->next);
		}
		return res;
    }

private:
	struct cmp {
		bool operator() (const ListNode* a, const ListNode* b)
		{
			return a->val > b->val;
		}
	};
};
