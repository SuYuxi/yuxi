class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<int> ans(N, 0);
		vector<vector<int>> g(N);;
		for(vector<int>& path : paths)
		{
			g[path[0] - 1].emplace_back(path[1] - 1);
			g[path[1] - 1].emplace_back(path[0] - 1);
		}
		for(int i = 0; i < N; i++)
		{
			vector<bool> used(5, false);
			for(int& adj : g[i])
			{
				used[ans[adj]] = true;
			}
			for(int color = 1; color <= 4; color++)
			{
				if(!used[color])
				{
					ans[i] = color;
					break;
				}
			}
		}
		return ans;
    }
};
