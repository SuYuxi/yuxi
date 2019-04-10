class Solution {
typedef pair<int, int> pairs;
public:
    int findPairs(vector<int>& nums, int k) {
		if(k < 0) return 0;
		unordered_map<int, int> map;
		for(int& num : nums)
		{
			map[num] += 1;
		}

		int cnt = 0;
		for(pair<const int, int>& p : map)
		{
			if(k == 0)
			{
				if(p.second > 1) cnt += 1;
			}
			else
			{
				if(map.count(p.first + k)) cnt += 1;
			}
		}
		return cnt;
    }
};
