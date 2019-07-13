//0-1 knapsack
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty()) return true;
        int sum = 0;
        for(int& num : nums)
        {
            sum += num;
        }
        if(sum % 2 == 1) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            for(int j = target; j > 0; j--)
            {
				if(dp[j]) continue;
                if(j - num >= 0 && dp[j - num])
                {
                    dp[j] = true;
                }
            }
            if(dp[target]) return true;
        }
        return dp[target];
    }
};
