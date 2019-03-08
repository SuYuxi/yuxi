//BackTracking
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
		if(grid.empty()) return 0;
		lenR = grid.size();
		lenC = grid[0].size();
		int todo = 0;
		for(int r = 0; r < lenR; r++)
		{
			for(int c = 0; c < lenC; c++)
			{
				if(grid[r][c] != -1)
				{
					todo++;
				}
				if(grid[r][c] == 1)
				{
					sR = r;
					sC = c;
				}
				else if(grid[r][c] == 2)
				{
					eR = r;
					eC = c;
				}
			}
		}
		int ans = 0;
		dfs(grid, sR, sC, todo, ans);
		return ans;
    }

	void dfs(vector<vector<int>>& grid, int r, int c, int todo, int& ans) {
		todo--;
		if(r == eR && c == eC && todo == 0)
		{
			ans++;
			return;
		}
		grid[r][c] = 3;
		for(int k = 0; k < 4; k++)
		{
			int nR = r + dirR[k];
			int nC = c + dirC[k];
			if(nR >= 0 && nR < lenR && nC >= 0 && nC < lenC)
			{
				if(grid[nR][nC] % 2 == 0)
				{
					dfs(grid, nR, nC, todo, ans);
				}
			}
		}
		grid[r][c] = 0;
	}

private:
	int sR, sC, eR, eC;
	int dirR[4] = {-1, 0, 1, 0};
	int dirC[4] = {0, -1, 0, 1};
	int lenR, lenC;
};

//Dynamic Programming 
//Bad efficiency
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
		if(grid.empty()) return 0;
		lenR = grid.size();
		lenC = grid[0].size();
		vector<vector<vector<int>>> dp(lenR, vector<vector<int>>(lenC, vector<int>(1 << (lenR * lenC), -1)));
		int todo = 0;
		for(int r = 0; r < lenR; r++)
		{
			for(int c = 0; c < lenC; c++)
			{
				if(grid[r][c] % 2 == 0)
				{
					todo |= encode(r, c);
				}
				if(grid[r][c] == 1)
				{
					sR = r;
					sC = c;
				}
				else if(grid[r][c] == 2)
				{
					eR = r;
					eC = c;
				}
			}
		}
		return dfs(grid, dp, sR, sC, todo);
    }

	int encode(int r, int c) {
		return 1 << (r * lenC + c);
	}

	int dfs(vector<vector<int>>& grid, vector<vector<vector<int>>> &dp, int r, int c, int todo) {
		if(dp[r][c][todo] != -1)
		{
			return dp[r][c][todo];
		}
		if(r == eR && c == eC)
		{
			return todo == 0 ? 1 : 0;
		}
		int ans = 0;
		for(int k = 0; k < 4; k++)
		{
			int nR = r + dirR[k];
			int nC = c + dirC[k];
			if(nR >= 0 && nR < lenR && nC >= 0 && nC < lenC)
			{
				if(todo & encode(nR, nC))
				{
					ans += dfs(grid, dp, nR, nC, todo ^ encode(nR, nC));
				}
			}
		}
		dp[r][c][todo] = ans;
		return ans;
	}

private:
	int sR, sC, eR, eC;
	int dirR[4] = {-1, 0, 1, 0};
	int dirC[4] = {0, -1, 0, 1};
	int lenR, lenC;
};
