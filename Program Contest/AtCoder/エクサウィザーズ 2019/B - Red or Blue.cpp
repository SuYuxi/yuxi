#include <string>
#include <iostream>

using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int r = 0;
	for(char& c : s)
		if(c == 'R') r++;
		else r --;
	if(r > 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
