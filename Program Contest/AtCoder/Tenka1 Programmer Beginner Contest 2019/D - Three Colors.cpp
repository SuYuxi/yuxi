#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 998244353;
int main()
{
	int N;
	cin >> N;
	vector<int> A(N, 0);
	for(int i = 0; i < N; i += 1) cin >> A[i];
	sort(A.begin(), A.end(), less<int>());
	return 0;
}
