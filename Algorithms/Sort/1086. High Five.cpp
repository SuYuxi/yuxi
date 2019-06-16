class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
		map<int, vector<int>, less<int>> hash;
		vector<vector<int>> ans;
		for(vector<int>& item : items)
		{
			hash[item[0]].emplace_back(item[1]);
		}
		for(auto& p : hash)
		{
			sort(p.second.begin(), p.second.end(), greater<int>());
			int sum = 0;
			for(int i = 0; i < min(5, (int)p.second.size()); i++)
			{
				sum += p.second[i];
			}
			sum /= min(5, (int)p.second.size());
			ans.push_back({p.first, sum});
		}
		return ans;
    }
};
