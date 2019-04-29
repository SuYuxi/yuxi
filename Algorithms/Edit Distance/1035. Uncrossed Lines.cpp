//dp
//longest common subsequence
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		int lenA = A.size(), lenB = B.size();
		vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1, 0));
		for(int i = 1; i <= lenA; i++)
		{
			for(int j = 1; j <= lenB; j++)
			{
				if(A[i - 1] == B[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[lenA][lenB];
    }
};
