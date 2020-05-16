class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        unordered_map<int, string> dp;
        backTracking(cost, dp, target);
        return dp[target];
    }
    
    void backTracking(vector<int>& cost, unordered_map<int, string>& dp, int target) {
        string maxPaint = "0";
        for(int num = 1; num <= 9; ++num)
        {
            int c = cost[num - 1];
            if(c > target) continue;
            if(c == target && maxPaint.size() == 1 && maxPaint < to_string(num))
            {
                maxPaint = to_string(num);
                continue;
            }
            if(dp.count(target - c) == 0)
            {    
                backTracking(cost, dp, target - c);
            }
            if(dp[target - c] != "0")
            {
                string xxx = to_string(num) + dp[target - c];
                if(xxx.size() > maxPaint.size() || (xxx.size() == maxPaint.size() && xxx > maxPaint)) {
                    maxPaint = xxx;
                }
            }
        }
        dp[target] = maxPaint;
    }
};
