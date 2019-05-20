//union find
//DSU Disjoint Set Union
#include <iostream>
#include <vector>
using namespace std;

class DSU {
public:
	DSU(int _size) : size(_size) {
		rank = vector<int>(size + 1, 1);
		parent = vector<int>(size + 1);
		for(int i = 0; i < size; i++)
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
	vector<int> rank;
	vector<int> parent;
};

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> X(M), Y(M), Z(M);
	for(int i = 0; i < M; i++)
	{
		cin >> X[i] >> Y[i] >> Z[i];
	}

	DSU dsu(N);
	int ans = N;
	for(int i = 0; i < M; i++)
	{
		ans -= dsu.Union(X[i], Y[i]);
	}

	cout << ans << endl;
	return 0;
}
