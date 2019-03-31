//topological sort
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		graph&& g = buildGraph(numCourses, prerequisites); 
		vector<int>&& indegrees = calculateIndegrees(g);

		vector<int> stack;
		for(int i = 0; i < numCourses; i += 1)
		{
			if(indegrees[i] == 0) stack.emplace_back(i);
		}

		while(!stack.empty())
		{
			int inx = stack.back();
			stack.pop_back();
			for(int& v : g[inx])
			{
				indegrees[v] -= 1;
				if(indegrees[v] == 0) stack.emplace_back(v);
			}
		}

		for(int& in : indegrees)
		{
			if(in != 0) return false;
		}
		return true;
    }

private:
	typedef vector<vector<int>> graph;
	graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisited) {
		graph g(numCourses);
		for(pair<int, int>& p : prerequisited)
		{
			g[p.second].emplace_back(p.first);
		}
		return g;
	}

	vector<int> calculateIndegrees(graph& g) {
		vector<int> indegrees(g.size(), 0);
		for(vector<int>& edges : g)
		{
			for(int& v : edges)
			{
				indegrees[v] += 1;
			}
		}
		return indegrees;
	}
};

