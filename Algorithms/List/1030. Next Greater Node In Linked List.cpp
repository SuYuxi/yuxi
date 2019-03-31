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
    vector<int> nextLargerNodes(ListNode* head) {
		vector<int> res, stack;
		for(ListNode* cur = head; cur != nullptr; cur = cur->next)
		{
			res.emplace_back(cur->val);
		}
		for(int inx = res.size() - 1, value; inx >= 0; inx -= 1)
		{
			value = res[inx];
			while(!stack.empty() && value >= stack.back())
			{
				stack.pop_back();
			}
			res[inx] = stack.empty() ? 0 : stack.back();
			stack.emplace_back(value);
		}
		return res;
    }
};
