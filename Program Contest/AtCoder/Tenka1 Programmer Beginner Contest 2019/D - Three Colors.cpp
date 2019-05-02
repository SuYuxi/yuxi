//https://betrue12.hateblo.jp/entry/2019/04/21/150214
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 998244353;

void add(long long& a, const long long& b)
{
	a = (a + b) % mod;
}

void mul(long long& a, const long long& b)
{
	a = (a * b) % mod;
}

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	int sum = 0;
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	vector<vector<long long>> dp(N + 1, vector<long long>(sum + 301, 0)); //dp[i][j]: first i nums has been painted, total value of red color is j, the number of ways to paint first i colors is dp[i][j].
	vector<vector<long long>> dp2(N + 1, vector<long long>(sum + 301, 0)); //dp[i][j]: first i nums has been painted into red or green(exclude blue), total value of red color is j, the number of ways to paint first i colors is dp[i][j].
	dp[0][0] = 1;
	dp2[0][0] = 1;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= sum; j++)
		{
			add(dp[i + 1][j + A[i]], dp[i][j]); //paint i-th into red color
			add(dp[i + 1][j], 2 * dp[i][j]); //paint i-th into other color
			add(dp2[i + 1][j + A[i]], dp2[i][j]); //paint i-th into red color
			add(dp2[i + 1][j], dp2[i][j]); //paint i-th into green color
		}
	}
	long long neg = 0;
	for(int j = (sum + 1) / 2; j <= sum; j++)
	{
		add(neg, dp[N][j]);	
	}
	if(sum % 2 == 0)
	{
		add(neg, mod - dp2[N][sum / 2]);
	}
	mul(neg, 3);
	long long ans = 1;
	for(int i = 0; i < N; i++) mul(ans, 3);
	add(ans, mod - neg);

	cout << ans << endl;
	return 0;
}
