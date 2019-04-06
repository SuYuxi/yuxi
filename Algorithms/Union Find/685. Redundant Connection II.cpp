class DSU {
public:
	DSU(int _size) : size(_size), rank(_size + 1, 1), parent(_size + 1)
	{
		for(int i = 0; i <= size; i += 1)
		{
			parent[i] = i;
		}
	}

	int find(int i)
	{
		if(parent[i] != i)
		{
			parent[i] = find(parent[i]);
		}
		return parent[i];
	}

	bool Union(int i, int j)
	{
		int ri = find(i), rj = find(j);
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
	int size;
	vector<int> parent;
	vector<int> rank;
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		DSU dsu(1000);
		vector<int> c1(2, 0), c2(2, 0);
		vector<int> parent(1001, 0);
		for(vector<int>& edge : edges)
		{
			if(parent[edge[1]] != 0)
			{
				c1 = {parent[edge[1]], edge[1]};
				c2 = edge;
				break;
			}
			parent[edge[1]] = edge[0];
		}
        
		for(vector<int>& edge : edges)
		{
			if((edge != c1) && (edge != c2))
			{
				if(!dsu.Union(edge[0], edge[1])) return edge;	
			}
		}
		if(!dsu.Union(c1[0], c1[1])) return c1;
		else return c2;
    }
};

