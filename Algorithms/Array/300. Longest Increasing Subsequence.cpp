//inspired by 334. Increasing Triplet Subsequence
//https://leetcode.com/problems/increasing-triplet-subsequence/discuss/78993/Clean-and-short-with-comments-C%2B%2B
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		if(nums.empty()) return 0;
		int res = 1;
		vector<int> dp(nums.size(), INT_MAX);
		for(int& num : nums)
		{
			int inx = 0;
			while(inx < dp.size())
			{
				if(num <= dp[inx])
				{
					dp[inx] = num;
					break;
				}
				else
				{
					inx += 1;
					res = max(res, inx + 1);
				}
			}
		}
		return res;
    }
};

//dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);
		int maxLIS = 0;
		for(int i = 0, maxCur = 0; i < nums.size(); i += 1, maxCur = 0)
		{
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
