#include <iostream>
#include <string>

using namespace std;
int main()
{
	double N, K;
	cin >> N >> K;
	double ans = 0;
	for(int i = 1; i <= N; i++)
	{
		double temp = 1.0 / N;
		int cur = i;
		while(cur < K)
		{
			cur *= 2;
			temp *= 0.5;
		}
		ans += temp;
	}
	printf("%.12f", ans);
	return 0;
}
