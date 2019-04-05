//Backtracking
//works both on cyclic or acyclic graph
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> paths;
		vector<bool> visited(N, false);
		vector<int> path;

		backtracking(graph, paths, path, 0, graph.size() - 1, visited);

		return paths;
    }

private:
	void backtracking(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path, int pos, int des, vector<bool> visited) {
		visited[pos] = true;
		path.emplace_back(pos);
		if(pos == des)
		{
			paths.emplace_back(path);
		}
		else
		{
			for(int& node : graph[pos])
			{
				if(!visited[node])
				{
					backtracking(graph, paths, path, node, des, visited);
				}
			}
		}
		visited[pos] = false;
		path.pop_back();
	}
};

//only works on acyclic graph
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> paths;
		vector<int> path;

		backtracking(graph, paths, path, 0, graph.size() - 1);

		return paths;
    }

private:
	void backtracking(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& path, int pos, int des) {
		path.emplace_back(pos);
		if(pos == des)
		{
			paths.emplace_back(path);
		}
		else
		{
			for(int& node : graph[pos])
			{
				backtracking(graph, paths, path, node, des);
			}
		}
		path.pop_back();
	}
};

//recursion
//extremely slow
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		return recursion(graph, 0);
    }

private:
	vector<vector<int>> recursion(vector<vector<int>>& graph, int node) {
		vector<vector<int>> paths;
		if(node == graph.size() - 1)
		{
			paths.emplace_back(vector<int>(1, graph.size() - 1));
			return paths;
		}
		for(int& next : graph[node])
		{
			for(vector<int> path : recursion(graph, next))
			{
				path.insert(path.begin(), node);
				paths.emplace_back(path);
			}
		}
		return paths;
	}
};
