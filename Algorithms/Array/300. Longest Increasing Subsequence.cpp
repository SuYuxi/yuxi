//inspired by 334. Increasing Triplet Subsequence
//https://leetcode.com/problems/increasing-triplet-subsequence/discuss/78993/Clean-and-short-with-comments-C%2B%2B
#include <algorithm>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int> LIS;
		for(int& num : nums)
		{
			vector<int>::iterator it = lower_bound(LIS.begin(), LIS.end(), num);
			if(it == LIS.end()) LIS.emplace_back(num);
			else *it = num;
		}
		return LIS.size();
    }
};

//dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		if(nums.empty()) return 0;
		vector<int> dp(nums.size(), 0);
		dp[0] = 1;
		int maxLIS = 1;
		for(int i = 1; i < nums.size(); i += 1)
		{
			int maxCur = 0;
			for(int j = 0; j < i; j += 1)
			{
				if(nums[i] > nums[j])
				{
					maxCur = max(maxCur, dp[j]);
				}
			}
			dp[i] = maxCur + 1;
			maxLIS = max(maxLIS, dp[i]);
		}
		return maxLIS;
	}
};
