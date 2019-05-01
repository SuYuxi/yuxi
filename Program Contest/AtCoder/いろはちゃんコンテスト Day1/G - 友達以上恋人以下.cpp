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
