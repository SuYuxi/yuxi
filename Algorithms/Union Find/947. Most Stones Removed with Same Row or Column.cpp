class DSU {
public:
	DSU(int n) {
		parent = vector<int>(n);
		rank = vector<int>(n, 1);
		for(int i = 0; i < n; i++)
		{
			parent[i] = i;
		}
	}

	int find(int i) {
		if(parent[i] != i)
		{
			parent[i] = find(parent[i]);
		}
		return parent[i];
	}

	void Union(int i, int j) {
		int pi = find(i);
		int pj = find(j);
		if(pi == pj) return;
		if(rank[pi] > rank[pj])
		{
			parent[pj] = pi;
		}
		else if(rank[pi] < rank[pj])
		{
			parent[pi] = pj;
		}
		else
		{
			parent[pj] = pi;
			rank[pi] = rank[pi] + 1;
		}
	}

private:
	vector<int> parent;
	vector<int> rank;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
		DSU dsu(20000);
		for(vector<int>& stone : stones)
		{
			dsu.Union(stone[0] + 10000, stone[1]);	
		}
		unordered_set<int> S;
		for(vector<int>& stone : stones)
		{
			S.insert(dsu.find(stone[1]));
		}
		return stones.size() - S.size();
    }
};

//DFS
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
		int size = stones.size();
		vector<vector<int>> graph(size, vector<int>(size, 0));
		for(int i = 0; i < size; i++)
		{
			for(int j = i + 1; j < size; j++)
			{
				if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
				{
					graph[i][++graph[i][0]] = j;
					graph[j][++graph[j][0]] = i;
				}
			}
		}
 
		int ans = 0;
		vector<bool> seen(size, false);
		for(int i = 0; i < size; i++)
		{
			if(!seen[i])
			{
				vector<int> toVisit = {i};
				seen[i] = true;
				ans--;
				while(!toVisit.empty())
				{
					int node = toVisit.back();
					toVisit.pop_back();
					ans++;
					for(int j = 1; j <= graph[node][0]; j++)
					{
						int inx = graph[node][j];
						if(!seen[inx])
						{
							toVisit.emplace_back(inx);
							seen[inx] = true;
						}
					}
				}
			}
		}
		return ans;
    }
};
