class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
		unordered_set<int64_t> visited;	
		for(vector<int>& b : blocked)
		{
			visited.insert(((int64_t)b[0] << 32) + b[1]);
		}
		return bfs(visited, source, target) && bfs(visited, target, source);
    }

private:
	bool bfs(unordered_set<int64_t> visited, vector<int>& source, vector<int>& target) {
		vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		queue<pair<int, int>> toVisit;
		toVisit.emplace(make_pair(source[0], source[1]));
		int coverArea = 0;
		while(!toVisit.empty())
		{
			pair<int, int> p = toVisit.front();
			toVisit.pop();
			if(++coverArea > 2e4) return true;
			for(vector<int>& dir : dirs)
			{
				int x = p.first + dir[0], y = p.second + dir[1];
				if(x >= 0 && y >= 0 && x < 1e6 && y < 1e6)
				{
					if(x == target[0] && y == target[1]) return true;
					if(visited.insert(((int64_t)x << 32) + y).second)
					{
						toVisit.emplace(make_pair(x, y));	
					}
				}
			}
		}
		return false;
	}
};
