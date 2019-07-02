class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, long lower, long upper) {
		long left = lower;
		vector<string> res;
		for(int i = 0; i < nums.size(); i++)
		{
			if(lower + 1 < nums[i])
			{
				res.emplace_back(to_string(lower) + "->" + to_string(nums[i] - 1));
			}
			else if(lower + 1 == nums[i])
			{
				res.emplace_back(to_string(lower));
			}
			lower = (long)nums[i] + 1;
		}
		if(lower < upper)
		{
			res.emplace_back(to_string(lower) + "->" + to_string(upper));
		}
		else if(lower == upper)
		{
			res.emplace_back(to_string(upper));
		}
		return res;
    }
};
