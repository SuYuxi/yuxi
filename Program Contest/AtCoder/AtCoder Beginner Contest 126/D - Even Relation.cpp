#include <bits/stdc++.h>

using namespace std;

int colors;
unordered_map<int, vector<pair<int, int>>> edges;

void dfs(int idx, int prev, int color) {
	colors[idx] = color;
	for(int i = 0; i < edges[idx].size(); i++)
	{
		int next = edges[idx][i].first;
		if(next == prev) continue;
		int dist = edges[idx][i].second;
		if(dist % 2 == 0)
		{
			dfs(next, idx, color);
		}
		else
		{
			dfs(next, idx, color ^ 1);
		}
	}
}

int main()
{
	int N;
	cin >> N;
	int x, y, z;
	for(int i = 0; i < N - 1; i++)
	{
		cin >> x >> y >> z;
		edges[x].emplace_back(make_pair(y, z));
		edges[y].emplace_back(make_pair(x, z));

	}
	colors = vector<int>(N + 1);
	dfs(1, -1, 0);
	for(int i = 1; i <= N; i++)
	{
		cout << colors[i] << endl;
	}
	return 0;
}
