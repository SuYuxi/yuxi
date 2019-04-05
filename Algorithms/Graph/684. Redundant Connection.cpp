//Find union
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	}
};

//Depth first search
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<vector<int>> graph(1001, vector<int>());
		unordered_set<int> visited;
		for(vector<int>& edge : edges)
		{
			visited.clear();
			if(!graph[edge[0]].empty() && !graph[edge[1]].empty() && dfs(graph, edge[0], edge[1], visited))
				return edge;
			graph[edge[0]].emplace_back(edge[1]);
			graph[edge[1]].emplace_back(edge[0]);
		}

		return vector<int>();
    }

private:
	bool dfs(vector<vector<int>>& graph, int from, int target, unordered_set<int>& visited) {
		if(!visited.count(from))
		{
			visited.insert(from);
			if(from == target) return true;
			for(int& node : graph[from])
			{
				if(dfs(graph, node, target, visited)) return true;
			}
		}
		return false;
	}
};
