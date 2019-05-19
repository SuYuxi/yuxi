#include <queue>
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
		priority_queue<int, vector<int>, less<int>> heap(stones.begin(), stones.end());
		int ans = 0;
		while(heap.size() > 1)
		{
			int m = heap.top();
			heap.pop();
			int n = heap.top();
			heap.pop();
            if(m - n != 0) heap.emplace(abs(m - n)); 
		} 
		return heap.size() == 1 ? heap.top() : 0;
    }
};
