class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
	    unordered_map<int, int> hashmap;
		int res = 0;
		for(vector<int>& row : wall)
		{
			int sum = 0;
			for(int i = 0; i < row.size() - 1; i += 1)
			{
				sum += row[i];
				res = max(res, ++hashmap[sum]);
			}
		}
		return wall.size() - res;
    }
};
