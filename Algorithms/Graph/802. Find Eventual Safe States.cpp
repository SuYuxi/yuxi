class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int size = graph.size();
		//color: 0 unvisited, 1 unsafe, 2 safe.
		vector<int> color(size, 0);
		vector<int> ans;
		for(int i = 0; i < size; i += 1)
		{
			if(dfs(graph, i, color))
			{
				ans.emplace_back(i);
			}
		}
		return ans;
    }

private:
	bool dfs(vector<vector<int>>& graph, int node, vector<int>& color)
	{
		if(color[node] > 0)
		{
			return color[node] == 2;
		}
		color[node] = 1;
		for(int& next : graph[node])
		{
			if(color[next] == 1) return false;
			if(color[next] == 0 && !dfs(graph, next, color)) return false;
		}
		color[node] = 2;
		return true;
	}
};
