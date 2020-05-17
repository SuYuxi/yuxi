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

//top-down
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        dp = vector<string>(target + 1);
        return dfs(cost, target);
    }
        
private:
    string dfs(vector<int>& cost, int target) {
        if(target <= 0) return target == 0 ? "" : "0";
        if(!dp[target].empty()) return dp[target];
        string res = "0";
        for(int num = 1; num <= 9; ++num)
        {
            int c = cost[num - 1];
            string str = dfs(cost, target - c);
            if(str != "0" && str.size() + 1 >= res.size())
            {
                res = to_string(num) + str;
            }
        }
        dp[target] = res;
        return dp[target];
    }

    vector<string> dp;
};
