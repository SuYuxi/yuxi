class Solution {
public:
    int superEggDrop(int K, int N) {
		vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0)); //dp[k][n] = floors, the maximum floors you can confirm by k eggs and n moves 
		int step = 0;
		while(dp[K][step] < N)
		{
			step++;
			for(int k = 1; k <= K; ++k)
			{
				dp[k][step] = 1 + dp[k][step - 1] + dp[k - 1][step - 1];
			}
		}
		return step;
	}
};

class Solution {
public:
    int superEggDrop(int K, int N) {
		dp = vector<vector<int>>(K + 1, vector<int>(N + 1, INT_MAX));
		return dfs(K, N);
    }
private:
	vector<vector<int>> dp;
	
	int dfs(int K, int N) {
		if(dp[K][N] != INT_MAX) return dp[K][N];
		int ans;
		if(N == 0)
		{
			ans = 0;
		}
		else if(K == 1)
		{
			ans = N;
		}
		else
		{
			int lo = 1, hi = N;
			while(lo + 1 < hi)
			{
				int X = (lo + hi) / 2;
				int t1 = dfs(K - 1, X - 1);
				int t2 = dfs(K, N - X);
				if(t1 > t2)
				{
					hi = X;
				}
				else if (t1 < t2)
				{
					lo = X;
				}
				else
				{
					lo = hi = X;
				}
			}
			ans = 1 + min(max(dfs(K - 1, lo - 1), dfs(K, N - lo)), max(dfs(K - 1, hi - 1), dfs(K, N - hi)));
		}
		dp[K][N] = ans;
		return dp[K][N];
	}
};
