//2-d DP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len1 + len2 != len3) {
            return false;
        }
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        for (int sublen_s1 = 1; sublen_s1 <= len1; sublen_s1 += 1) {
            dp[sublen_s1][0] = dp[sublen_s1 - 1][0] && s1[sublen_s1 - 1] == s3[sublen_s1 - 1];
        }
        for (int sublen_s2 = 1; sublen_s2 <= len2; sublen_s2 += 1) {
            dp[0][sublen_s2] = dp[0][sublen_s2 - 1] && s2[sublen_s2 - 1] == s3[sublen_s2 - 1];
        }
        for (int sublen_s1 = 1; sublen_s1 <= len1; sublen_s1 += 1) {
            for (int sublen_s2 = 1; sublen_s2 <= len2; sublen_s2 += 1) {
                    dp[sublen_s1][sublen_s2] = (dp[sublen_s1][sublen_s2 - 1] && s2[sublen_s2 - 1] == s3[sublen_s1 + sublen_s2 - 1]) || (dp[sublen_s1 - 1][sublen_s2] && s1[sublen_s1 - 1] == s3[sublen_s1 + sublen_s2 - 1]);
            }
        }
        return dp[len1][len2];
    }
};

//1-d Dp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<bool> dp(s2.size() + 1);
        dp[0] = true;
        for (int j = 1; j <= s2.size(); j += 1) {
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        }
        for (int i = 1; i <= s1.size(); i += 1) {
            for (int j = 0; j <= s2.size(); j += 1) {
                if (j == 0) {
                    dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
                }
                else {
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1]) && s2[j - 1] == s3[i + j - 1];
                }
            }
        }
        return dp[s2.size()];
    }
};
