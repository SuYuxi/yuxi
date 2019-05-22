#include <bits/stdc++.h>
//Union find + Backtracking + Graph
class DSU {
public:
	DSU() {} 
	string find(string i)
	{
		if(parent[i] != i)
		{
			parent[i] = find(parent[i]);
		}
		return parent[i];
	}

	bool Union(string i, string j)
	{
		if(parent.count(i) == 0)
		{
			parent[i] = i;
			rank[i] = 1;
		}
		if(parent.count(j) == 0)
		{
			parent[j] = j;
			rank[j] = 1;
		}
		string ri = find(i), rj = find(j);
		if(ri == rj) return false;
		if(rank[ri] < rank[rj])
		{
			parent[ri] = rj;
		}
		else if(rank[ri] > rank[rj])
		{
			parent[rj] = ri;
		}
		else
		{
			parent[rj] = ri;
			rank[ri] += 1;
		}
		return true;
	}


private:
	unordered_map<string, string> parent;
	unordered_map<string, int> rank;
};


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> edges;
		DSU dsu;
		for(int i = 0; i < equations.size(); i++)
		{
			vector<string> equation = equations[i];	
			dsu.Union(equation[0], equation[1]);
			double value = values[i];
			edges[equation[0]][equation[1]] = values[i];
			edges[equation[1]][equation[0]] = 1.0 / values[i];
		}
		vector<double> res;
		for(vector<string>& query : queries)
		{
			unordered_set<string> visited;
			if(edges.count(query[0]) == 0 | edges.count(query[1]) == 0 | dsu.find(query[0]) != dsu.find(query[1]))
			{
				res.emplace_back(-1.0);
			}
			else
			{
				visited.insert(query[0]);
				backtracking(edges, visited, query[0], query[1], 1.0, res);
			}
			
		}
		return res;
    }

private:
	void backtracking(unordered_map<string, unordered_map<string, double>>& edges, unordered_set<string>& visited, string cur, string target, double value, vector<double>& res)
	{
		if(cur == target)
		{
			res.emplace_back(value);
			return;
		}
		for(auto& p : edges[cur])
		{
			if(visited.count(p.first) == 0)
			{
				visited.insert(p.first);
				backtracking(edges, visited, p.first, target, value * p.second, res);
				visited.erase(p.first);
			}
		}
	}
};
