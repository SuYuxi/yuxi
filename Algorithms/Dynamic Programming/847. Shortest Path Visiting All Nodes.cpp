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

//Dp
//Bellman-Ford algorithm
const int INF = 1e9;
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
		if(graph.empty()) return 0;
		int N = graph.size();
		vector<vector<int>> dist(1 << N, vector<int>(N, INF));
		for(int start = 0; start < N; start += 1)
		{
			dist[1 << start][start] = 0; //distance from start
		}
		for(int path = 1; path < (1 << N); path += 1)
		{
			bool repeat = true;
			while(repeat)
			{
				repeat = false;
				for(int head = 0; head < N; head += 1)
				{
					int d = dist[path][head];
					for(int& child : graph[head])
					{
						int pathChild = path | (1 << child);
						if(d + 1 < dist[pathChild][child])
						{
							dist[pathChild][child] = d + 1;
							if(path == pathChild)
							{
								repeat = true;
							}
						}
					}
				}
			}
		}
		int res = INF;
		for(int& d : dist[(1 << N) - 1])
		{
			res = min(res, d);
		}
		return res;
	}
};
