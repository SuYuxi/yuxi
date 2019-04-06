//Find Union
//DSU Disjoint Set Union
//O(n)

class DSU {
public:
	DSU(int _size) : size(_size) {
		rank = vector<int>(size + 1, 1);
		parent = vector<int>(size + 1, 0);
		for(int i = 1; i < size + 1; i += 1)
		{
			parent[i] = i;
		}
	}
	
	int find(int i) {
		int r = i;
		while(parent[r] != r)
		{
			r = parent[r];
		}
		int temp;
		while(parent[i] != i) // comparentss path
		{
			temp = parent[i];
			parent[i] = r;
			i = temp;	
		}
		return parent[i];
	}

	bool Union(int i, int j) {
		int ri = find(i), rj = find(j);
		if(ri == rj) return false;
		if(rank[ri] > rank[rj])
		{
			parent[rj] = ri;
		}
		else if (rank[ri] < rank[rj])
		{
			parent[ri] = rj;
		}
		else
		{
			parent[rj] = ri;
			rank[ri] += 1;
		}
		return true;
	}

private:
	int size;
	vector<int> parent;
	vector<int> rank;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		DSU dsu = DSU(1000);
		for(vector<int>& edge : edges)
		{
			if(!dsu.Union(edge[0], edge[1]))
				return edge;
		}
		return vector<int>();
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
			if(dfs(graph, edge[0], edge[1], visited)) return edge;
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
