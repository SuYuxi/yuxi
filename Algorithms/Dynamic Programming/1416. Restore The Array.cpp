class Solution {
public:
    int numberOfArrays(string s, int k) {
        if(s.empty()) return 0;
        int len = s.size();
        int dp[len + 1];
        dp[len] = 1; 
        for(int i = len - 1; i >= 0; --i)
        {
            dp[i] = 0;
            if(s[i] == '0') continue;
            long num = 0;
            for(int j = i; j < len; ++j)
            {
                num = num * 10 + (s[j] - '0');
                if(num > k) break;
                dp[i] = (dp[i] + dp[j + 1]) % 1000000007;
            }
        }
        return dp[0];
    }
};
