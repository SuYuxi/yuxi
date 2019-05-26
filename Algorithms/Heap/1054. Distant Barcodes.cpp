#include <priority_queue>
#include <unordered_map>

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		auto cmp = [](pair<int, int>& a, pair<int, int>& b){ return a.first < b.first;};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
		unordered_map<int, int> umap;
		vector<int> res;
		for(int& barcode : barcodes)
		{
			umap[barcode]++;
		}
		for(pair<const int, int>& p : umap)
		{
			heap.emplace(make_pair(p.second, p.first));
		}

		while(!heap.empty())
		{
			pair<int, int> p1 = heap.top();
			heap.pop();
			if(res.empty() || p1.second != res.back() || heap.empty())
			{
				res.emplace_back(p1.second);
				p1.first--;
				if(p1.first > 0)
				{
					heap.emplace(p1);
				}
			}
			else
			{
				pair<int, int> p2 = heap.top();
				heap.pop();
				heap.emplace(p1);
				res.emplace_back(p2.second);
				p2.first--;
				if(p2.first > 0)
				{
					heap.emplace(p2);
				}
			}
		}
		return res;
    }
};
