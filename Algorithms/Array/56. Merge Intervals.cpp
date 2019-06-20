class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if(intervals.empty()) return vector<vector<int>>();
		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
		vector<vector<int>> ans;
		ans.emplace_back(intervals.front());
		for(int i = 1; i < intervals.size(); i++)
		{
			if(intervals[i][0] > ans.back()[1])
			{
				ans.emplace_back(intervals[i]);
			}
			else
			{
				ans.back()[1] = max(intervals[i][1], ans.back()[1]);
			}
		}
		return ans;
    }
};
