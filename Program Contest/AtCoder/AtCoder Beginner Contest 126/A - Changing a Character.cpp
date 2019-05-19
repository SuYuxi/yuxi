#include <iostream>
#include <string>

using namespace std;
int main()
{
	int N, K;
	string S;
	cin >> N >> K;
	cin >> S;
	if(S[K - 1] >= 'A' && S[K - 1] <= 'Z')
	{
		S[K - 1] += 32;
	}
	cout << S << endl;
	return 0;
}
