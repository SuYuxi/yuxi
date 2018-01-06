class Solution {
public:
    int numDistinct(string s, string t) {
		int m = s.size(), n = t.size();
		vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
		for(int i = 0; i <= m; ++i) dp[i][0] = 1;
		for(int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				dp[i][j] = dp[i-1][j] + (s[i-1] == t[j-1] ? dp[i-1][j-1] : 0);   
			}
		}
		return dp[m][n];
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
		int m = s.size(), n = t.size();
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		int temp, pre;
		for(int i = 1; i <= m; ++i) {
			pre = 1;
			for (int j = 1; j <= n; ++j) {
				temp = dp[j];	
				dp[j] = dp[j] + (s[i-1] == t[j-1] ? pre : 0);   
				pre = temp;
			}
		}
		return dp[n];
    }
};
