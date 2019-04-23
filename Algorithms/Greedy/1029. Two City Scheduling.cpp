class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
		sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] - a[1] < b[0] - b[1]; });
		int ans = 0;
		int inx1 = 0, inx2 = costs.size() - 1;
		while(inx1 < inx2)
		{
			ans += costs[inx1][0] + costs[inx2][1];
			inx1++;
			inx2--;
		}
		return ans;
    }
};
