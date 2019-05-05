const int INF = 1e9;

//top-down
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
		vector<vector<int>> dp(A.size(), vector<int>(A.size(), -1));
		return helper(A, dp, 0, A.size() - 1);
    }
private:
	int helper(vector<int>& A, vector<vector<int>>& dp, int start, int end) {
		if(end - start < 2) return 0;
		if(dp[start][end] != -1) return dp[start][end];
		int product = A[start] * A[end];
		dp[start][end] = INF;
		for(int i = start + 1; i < end; i++)
		{
			dp[start][end] = min(dp[start][end], product * A[i] + helper(A, dp, start, i) + helper(A, dp, i, end)); 
		}
		return dp[start][end];
	}
};

//bottom-up
const int INF = 1e9;

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
		int n = A.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for(int len = 2; len < n; len++)
		{
			for(int start = 0; start + len < n; start++)
			{
				int end = start + len;
				dp[start][end] = INF;
				int product = A[start] * A[end];
				for(int i = start + 1; i < end; i++)
				{
					dp[start][end] = min(dp[start][end], product * A[i] + dp[start][i] + dp[i][end]);
				}
			}
		}

		return dp[0][n - 1];
    }
};
