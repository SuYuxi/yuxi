#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int k;
	cin >> s;
	cin >> k;
	k = k % s.size();
	string ans;
	ans += s.substr(k, string::npos) + s.substr(0, k); 
	cout << ans << endl;
	return 0;
}
