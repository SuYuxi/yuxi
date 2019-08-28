class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
		if(grid.empty()) return -1;
        int m = grid.size(), n = grid[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		deque<pair<int, int>> queue;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
					queue.emplace_back(make_pair(i, j));
					visited[i][j] = true;
                }
            }
        }
		int level = -1;
		int x, y;
		while(!queue.empty())
		{
			int size = queue.size();
			for(int i = 0; i < size; ++i)
			{
				tie(x, y) = queue.front();
				queue.pop_front();

				for(int d = 0; d < 4; ++d)
				{
					int newX = x + directions[d][0];
					int newY = y + directions[d][1];
					if(newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY])
					{
						queue.emplace_back(make_pair(newX, newY));
						visited[newX][newY] = true;
					}
				}
			}
			level++;
		}
        return level <= 0 ? -1 : level;
    }

private:
	int directions[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
};
