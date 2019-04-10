//Breadth-first search
const int INF = 1e9;
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
		if(graph.empty()) return 0;
		int N = graph.size();
		vector<vector<int>> dist(1 << N, vector<int>(N, INF));
		queue<pair<int, int>> q; //(visited nodes, head)
		
		for(int start = 0; start < N; start += 1)
		{
			q.emplace(make_pair(1 << start, start));
			dist[1 << start][start] = 0; //distance from start
		}
		
		while(!q.empty())
		{
			pair<int, int> node = q.front();
			q.pop();
			int d = dist[node.first][node.second]; 
			if(node.first == (1 << N) - 1) return d; 

			for(int& child : graph[node.second])
			{
				int path = node.first | (1 << child);
				if(d + 1 < dist[path][child])
				{
					q.emplace(make_pair(path, child));
					dist[path][child] = d + 1;
				}
			}
		}
		return -1;
    }
};
