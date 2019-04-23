#include <iostream>
#include <string>
using namespace std;
int main()
{
	int N, K;
	string S;
	cin >> N >> S >> K;
	char target = S[K - 1];
	for(char& c : S)
	{
		if(c != target) cout << '*';
		else cout << c;
	}
	cout << endl;
	return 0;
}
