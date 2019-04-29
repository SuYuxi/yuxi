#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int Inf = 1e9;
int main()
{
	int N;
	cin >> N;
	vector<long> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	long cnt = 0, Sum = 0;
	long Min = Inf;
	for(long& num : A)
	{
		if(num < 0) cnt++;
		Sum += abs(num);
		Min = min(Min, abs(num));
	}
	if(cnt % 2 == 0) cout << Sum << endl;
	else cout << Sum - Min * 2 << endl;

	return 0;
}
