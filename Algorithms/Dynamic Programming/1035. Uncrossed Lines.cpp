class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		int lenA = A.size(), lenB = B.size();
		if(A.empty() || B.empty()) return 0;
		vector<vector<int>> dp(lenA, vector<int>(lenB, 0));
		unordered_map<int, int> hashA, hashB;
		for(int i = 0; i < lenA; i++) { hashA[A[i]] = i; }
		for(int i = 0; i < lenB; i++) { hashB[B[i]] = i; }
		dp[0][hashB[A[0]]] = 1;
		dp[hashA[B[0]]][0] = 1;
		for(int i = 1; i < lenA; i++)
		{
			for(int j = 1; j < lenB; j++)
			{
				dp[i][j] = max(dp[i - 1][j - 1]
			}
		}
    }
};
