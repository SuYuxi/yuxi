//dp
//https://img.atcoder.jp/iroha2019-day1/editorial-G.pdf
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
const int INF = 1e9;
int N, M, K;
vector<int> A;
vector<vector<long long>> dp;
 
long long dfs(int i, int j) {
	if(j == 0)
	{
		if(i + K - 1 >= N)
		{
			return A[i - 1];
		}
		else
		{
			return -INF;
		}
	}
	if(i >= N) return -INF;
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	long long MAX = -INF;
	for(int k = 0; k < K && i + k < N; k++)
	{
		MAX = max(MAX, dfs(i + k + 1, j - 1));
	}
	dp[i][j] = MAX + (i != 0 ? A[i - 1] : 0);
	return dp[i][j];
}
int main() {
	cin >> N >> M >> K;
	A = vector<int>(N);
	dp = vector<vector<long long>>(N + 1, vector<long long>(M + 1, -1));
	for(int i = 0; i < N; i++) cin >> A[i];
	cout << max(dfs(0, M), -1LL) << endl;
	return 0;
}

//dp + rmq
//https://img.atcoder.jp/iroha2019-day1/editorial-G.pdf
#include <iostream>
#include <vector>
#include <cmath>
const int INF = 1e12;

using namespace std;

class SegmentTree{
public:
	SegmentTree(const vector<long long>& A) {
		size = A.size();
		if(size > 0)
		{
			segmentTree = vector<long long>(4 * size, -INF);
			build(A, 0, size - 1, 0);
		}
	}
	void build(const vector<long long>& A, int start, int end, int inx) {
		if(start == end)
		{
			segmentTree[inx] = A[start];
			return;
		}
		int mid = (start + end) / 2;
		build(A, start, mid, 2 * inx + 1);
		build(A, mid + 1, end, 2 * inx + 2);
		segmentTree[inx] = max(segmentTree[2 * inx + 1], segmentTree[2 * inx + 2]);
	};

	void update(int i, long long value) {
		update(0, size - 1, i, value, 0);
	};

	long long query(int i, int j) {
		return query(0, size - 1, i, j, 0);
	};

private:
	void update(int start, int end, int i, long long value, int inx) {
		if(start == end)
		{
			segmentTree[inx] = value;
			return;
		}
		int mid = (start + end) / 2;
		if(i <= mid)
		{
			update(start, mid, i, value, 2 * inx + 1);
		}
		else
		{
			update(mid + 1, end, i, value, 2 * inx + 2);
		}
		segmentTree[inx] = max(segmentTree[2 * inx + 1], segmentTree[2 * inx + 2]);
	}

	long long query(int start, int end, int i, int j, int inx) {
		if(start > j || end < i) return -INF;
		if(i <= start && j >= end) return segmentTree[inx];
		int mid = (start + end) / 2;
		return max(query(start, mid, i, j, 2 * inx + 1), query(mid + 1, end, i, j, 2 * inx + 2)); 
	}

	vector<long long> segmentTree;
	int size;
}; 

int N, M, K;
vector<int> A;
vector<vector<long long>> dp;
vector<SegmentTree> rmq;
 
long long dfs(int i, int j) {
	if(j == 0)
	{
		if(N <= i + K - 1)
		{
			dp[i][j] = A[i - 1];
		}
		else
		{
			dp[i][j] = -INF;
		}
		rmq[j].update(i, dp[i][j]);
		return dp[i][j];
	}
	if(i >= N) return -INF;
	if(dp[i][j] != -1) return dp[i][j];
	dp[i][j] = rmq[j - 1].query(i + 1, min(i + K, N)) + (i != 0 ? A[i - 1] : 0);
	rmq[j].update(i, dp[i][j]);
	return dp[i][j];
}

int main() {
	cin >> N >> M >> K;
	A = vector<int>(N, 0);
	dp = vector<vector<long long>>(N + 1, vector<long long>(M + 1, -1));
	rmq = vector<SegmentTree>(M + 1, vector<long long>(N + 1));
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int j = 0; j <= M; j++)
	{
		for(int i = N; i >= 0; i--) dfs(i, j);
	}
	cout << max(dp[0][M], -1LL) << endl;
	return 0;
}
