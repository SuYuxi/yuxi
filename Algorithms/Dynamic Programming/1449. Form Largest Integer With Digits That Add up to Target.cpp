//bottom-up
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target + 1, "0");
        dp[0] = "";
        for(int t = 1; t <= target; ++t)
        {
            for(int num = 1; num <= 9; ++num)
            {
                int c = cost[num - 1];
                if(c <= t && dp[t - c] != "0")
                {
                    if(dp[t].size() <= dp[t - c].size() + 1)
                    {
                        dp[t] = to_string(num) + dp[t - c];
                    }
                }
            }
        }
        return dp[target];
    }
};
