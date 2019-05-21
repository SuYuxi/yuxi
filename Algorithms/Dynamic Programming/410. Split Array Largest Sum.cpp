//dp
#include <bits/stdc++.h>
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
		int size = nums.size();
		vector<vector<int>> dp(size + 1, vector<int>(m + 1, INT_MAX));
		vector<long> sub(size + 1, 0);
		for(int i = 0; i < size; i++)
		{
			sub[i + 1] = sub[i] + nums[i];
		}
		dp[0][0] = 0;
		for(int i = 1; i <= size; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				for(int k = 0; k < i; k++)
				{
					dp[i][j] = min(dp[i][j], max(dp[k][j - 1], int(sub[i] - sub[k])));
				}
			}
		}
		return dp[size][m];
    }
};

//binary search & greedy
#include <bits/stdc++.h>
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
		
		long left = *max_element(nums.begin(), nums.end());
		long right = accumulate(nums.begin(), nums.end(), 0L);
		while(left < right)
		{
			long mid = (left + right) >> 1;
			if(canSplit(nums, m, mid))
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		return left;
	}

private:
	bool canSplit(vector<int>& nums, int m, long maxSum) {
		int cnt = 1;
		long sum = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			if(sum > maxSum)
			{
				cnt++;
				sum = nums[i];
				if(cnt > m) return false;
			}
		}
		return true;
	}
};
