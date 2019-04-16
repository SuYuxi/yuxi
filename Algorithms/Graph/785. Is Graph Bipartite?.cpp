//Breadth first search
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
		queue<int> q;    
		vector<int> visited(graph.size(), -1);
		for(int i = 0; i < graph.size(); i++)
		{
			if(visited[i] == -1)
			{
				q.emplace(i);
				visited[i] = 0;
				while(!q.empty())
				{
					int node = q.front();
					q.pop();
					for(int& next : graph[node])
					{
						if(visited[next] == visited[node]) return false;
						if(visited[next] == -1)
						{
							q.emplace(next);
							visited[next] = 1 - visited[node];
						}
					}
				}
			}
		}
		return true;
    }
};

//Depth first search
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
		vector<int> visited(graph.size(), -1);
		for(int i = 0; i < graph.size(); i++)
		{
			if(visited[i] == -1)
			{
				visited[i] = 0;
				if(!dfs(graph, visited, i)) return false;	
			}
		}
		return true;
	}
private:
	bool dfs(vector<vector<int>>& graph, vector<int>& visited ,int node) {
		for(int& next : graph[node])
		{
			if(visited[next] == -1)
			{
				visited[next] = 1 - visited[node];
				if(!dfs(graph, visited, next)) return false;
			}
			else if(visited[next] == visited[node])
			{
				return false;
			}
		}
		return true;
	}
};
