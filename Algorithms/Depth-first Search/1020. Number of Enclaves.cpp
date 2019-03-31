class Solution {

public:
    int numEnclaves(vector<vector<int>>& A) {
		if(A.empty()) return 0;
		int R = A.size(), C = A[0].size(); 
		for(int col = 0; col < C; col += 1)
		{
			dfs(A, 0, col, R, C);
			dfs(A, R - 1, col, R, C);
		}
		for(int row = 1; row < R - 1; row += 1)
		{
			dfs(A, row, 0, R, C);
			dfs(A, row, C - 1, R, C);
		}

		int res = 0;
		for(vector<int>& a : A)
		{
			for(int& num : a)
			{
				res += num;
			}
		}
		return res;
    }

private:
	void dfs(vector<vector<int>>& A, int row, int col, int R, int C)
	{
		if(row < 0 || col < 0 || row > R - 1 || col > C - 1) return;
		if(A[row][col] == 1)
		{
			A[row][col] = 0;
			dfs(A, row + 1, col, R, C);
			dfs(A, row - 1, col, R, C);
			dfs(A, row, col + 1, R, C);
			dfs(A, row, col - 1, R, C);
		}
	}
};
