//Depth-first Search
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		if(grid.empty()) return 0;
		int rowLen = grid.size(), colLen = grid[0].size();
		visited.assign(rowLen, vector<bool>(colLen, false));
		int cnt = 0;
		for(int row = 0; row < rowLen; row += 1)
		{
			for(int col = 0; col < colLen; col += 1)
			{
				if(!visited[row][col] && grid[row][col] == '1')
				{
					dfs(grid, row, col, rowLen, colLen);
					cnt += 1;
				}
			}
		}
		return cnt;
	}
private:
	vector<vector<bool>> visited;
	void dfs(vector<vector<char>>& grid, int row, int col, int rowLen, int colLen)
	{
		visited[row][col] = true;
		if(row > 0 && !visited[row - 1][col] && grid[row - 1][col] == '1')
		{
			dfs(grid, row - 1, col, rowLen, colLen);
		}
		if(row < rowLen - 1 && !visited[row + 1][col] && grid[row + 1][col] == '1')
		{
			dfs(grid, row + 1, col, rowLen, colLen);
		}
		if(col > 0 && !visited[row][col - 1] && grid[row][col - 1] == '1')
		{
			dfs(grid, row, col - 1, rowLen, colLen);
		}
		if(col < colLen - 1 && !visited[row][col + 1] && grid[row][col + 1] == '1')
		{
			dfs(grid, row, col + 1, rowLen, colLen);
		}
	}
};

//Breadth-first Search
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		if(grid.empty()) return 0;
		int rowLen = grid.size(), colLen = grid[0].size();
		visited.assign(rowLen, vector<bool>(colLen, false));
		int cnt = 0;
		for(int row = 0; row < rowLen; row += 1)
		{
			for(int col = 0; col < colLen; col += 1)
			{
				if(!visited[row][col])
				{
					if(grid[row][col] == '1')
					{
						traverse(grid, row, col, rowLen, colLen);
						cnt += 1;
					}
				}
			}
		}
		return cnt;
    }

private:
	queue<pair<int, int>> toVisit; //pair(row, col)
	vector<vector<bool>> visited;

	void traverse(vector<vector<char>>& grid, int row, int col, int rowLen, int colLen)
	{
		toVisit.emplace(make_pair(row, col));
		visited[row][col] = true;
		while(!toVisit.empty())
		{
			tie(row, col) = toVisit.front(); 
			toVisit.pop();	
			if(row > 0 && !visited[row - 1][col] && grid[row - 1][col] == '1')
			{
				toVisit.emplace(make_pair(row - 1, col));
				visited[row - 1][col] = true;
			}
			if(row < rowLen - 1 && !visited[row + 1][col] && grid[row + 1][col] == '1')
			{
				toVisit.emplace(make_pair(row + 1, col));
				visited[row + 1][col] = true;
			}
			if(col > 0 && !visited[row][col - 1] && grid[row][col - 1] == '1')
			{
				toVisit.emplace(make_pair(row, col - 1));
				visited[row][col - 1] = true;
			}
			if(col < colLen - 1 && !visited[row][col + 1] && grid[row][col + 1] == '1')
			{
				toVisit.emplace(make_pair(row, col + 1));
				visited[row][col + 1] = true;
			}
		}
	}
};

//destructive
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		if(grid.empty()) return 0;
		int rowLen = grid.size(), colLen = grid[0].size();
		int cnt = 0;
		for(int row = 0; row < rowLen; row += 1)
		{
			for(int col = 0; col < colLen; col += 1)
			{
				if(grid[row][col] == '1')
				{
					traverse(grid, row, col, rowLen, colLen);
					cnt += 1;
				}
			}
		}
		return cnt;
    }

private:
	queue<pair<int, int>> toVisit; //pair(row, col)

	void traverse(vector<vector<char>>& grid, int row, int col, int rowLen, int colLen)
	{
		toVisit.emplace(make_pair(row, col));
		while(!toVisit.empty())
		{
			tie(row, col) = toVisit.front(); 
			toVisit.pop();	
			if(row > 0 && grid[row - 1][col] == '1')
			{
				toVisit.emplace(make_pair(row - 1, col));
				grid[row - 1][col] = '0';
			}
			if(row < rowLen - 1 && grid[row + 1][col] == '1')
			{
				toVisit.emplace(make_pair(row + 1, col));
				grid[row + 1][col] = '0';
			}
			if(col > 0 && grid[row][col - 1] == '1')
			{
				toVisit.emplace(make_pair(row, col - 1));
				grid[row][col - 1] = '0';
			}
			if(col < colLen - 1 && grid[row][col + 1] == '1')
			{
				toVisit.emplace(make_pair(row, col + 1));
				grid[row][col + 1] = '0';
			}
		}
	}
};
