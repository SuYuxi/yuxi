//greedy
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	long long N, A;
	int B;
	cin >> N >> A >> B;
	vector<long long> D(B + 2);
	for(long long i = 0; i < B; i++) cin >> D[i];
	D[B] = 0;
	D[B + 1] = N + 1;
	sort(D.begin(), D.end());
	long long ans = 0;
	for(int i = 0; i < B + 1; i++)
	{
		long long days = D[i + 1] - D[i] - 1;
		ans += days - days / A;
	}
	cout << ans << endl;
	return 0;
}
