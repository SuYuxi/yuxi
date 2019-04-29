class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
		if(grid.empty()) return grid;
		int lenR = grid.size(), lenC = grid[0].size();
		visited = vector<vector<bool>>(lenR, vector<bool>(lenC, false));
		dfs(grid, grid[r0][c0], r0, c0, lenR, lenC);
		for(pair<int, int>& p : border)
		{
			grid[p.first][p.second] = color;
		}
		return grid;
    }

private:
	vector<vector<bool>> visited;
	vector<pair<int, int>> border;
	int dfs(vector<vector<int>>& grid, int cur, int r, int c, int lenR, int lenC) {
		if(c < 0 || r < 0 || c > lenC - 1 || r > lenR - 1 || grid[r][c] != cur) return 0;
		if(visited[r][c]) return 1;
		visited[r][c] = true;
		if(dfs(grid, cur, r + 1, c, lenR, lenC) + dfs(grid, cur, r - 1, c, lenR, lenC) + dfs(grid, cur, r, c + 1, lenR, lenC) + dfs(grid, cur, r, c - 1, lenR, lenC) < 4)
		{
			border.emplace_back(make_pair(r, c));
		}
		return 1;
	}
};
