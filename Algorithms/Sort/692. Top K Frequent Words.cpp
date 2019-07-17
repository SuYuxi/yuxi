class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for(string& w : words) cnt[w]++;
        vector<pair<int, string>> pairs;
        for(auto& p : cnt)
        {
            pairs.emplace_back(make_pair(p.second, p.first));
        }
		auto cmp = [](pair<int, string>& a, pair<int, string>& b){return a.first == b.first ? a.second > b.second : a.first < b.first;};
		priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> heap(cmp, pairs); 
        vector<string> res(k);
        for(int i = 0; i < k; i++)
        {
            res[i] = heap.top().second;
			heap.pop();
        }
        return res;
    }
};
