//Insert DP
//Explanation http://drken1215.hatenablog.com/entry/2019/04/01/201600
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int mod = 1000000007;
	int N, X;
	cin >> N >> X;
	vector<int> s(N, 0);
	for(int i = 0; i < N; i += 1)
	{
		cin >> s[i];
	}
	sort(s.begin(), s.end());
	vector<vector<long>> dp(N + 1, vector<long>(X + 1, 0)); //dp[N][X] N is order i and X is first number on black board
	for(int x = 0; x <= X; x += 1)
	{
		dp[1][x] = x % s[0];
	}

	for(int i = 1; i < N; i += 1)
	{
		for(int x = 0; x <= X; x += 1)
		{
			dp[i + 1][x] = (dp[i][x % s[i]] + i * dp[i][x]) % mod; //insert in front of array and in mid of array
		}
	}
	cout << dp[N][X] << endl;
	return 0;
}

