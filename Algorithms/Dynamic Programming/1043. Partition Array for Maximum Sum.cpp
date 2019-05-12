class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
		int size = A.size();
		vector<int> dp(size, 0);
		for(int i = 0; i < size; ++i)
		{
			int curMax = 0;
			for(int k = 1; k <= K && (i - k + 1 >= 0); ++k)
			{
				curMax = max(curMax, A[i - k + 1]);
				dp[i] = max(dp[i], (i - k >= 0 ? dp[i - k] : 0) + curMax * k);
			}
		}
		return dp[size - 1];
    }
};
