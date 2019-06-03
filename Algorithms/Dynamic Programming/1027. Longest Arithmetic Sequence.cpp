class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
		int N = A.size();
		vector<unordered_map<int, int>> dp(N); //dp[index][diff] == longest length until index
		int ans = 0;
		for(int i = 1; i < N; i++)
		{
			for(int j = 0; j < i; j++)
			{
				int diff = A[i] - A[j];
				if(dp[j].count(diff) == 0) dp[j][diff] = 1;
				dp[i][diff] = dp[j][diff] + 1;
				ans = max(ans, dp[i][diff]);
			}
		}
		return ans; 
    }
};
