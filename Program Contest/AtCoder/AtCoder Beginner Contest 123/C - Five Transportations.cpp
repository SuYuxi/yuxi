//only consider the lowest volume of traffic
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long N, A, B, C, D, E;
	cin >> N >> A >> B >> C >> D >> E;

	cout << ((N - 1) / min(A, min(B, min(C, min(D, E)))) + 1) + 4 << endl;
	return 0;
}
