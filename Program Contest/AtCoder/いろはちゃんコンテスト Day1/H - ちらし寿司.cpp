//greedy
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	if(s.size() == 1)
	{
		cout << "1" << --s[0] << endl;
		return 0;
	}
	int sum = 0;
	for(char& c : s)
	{
		sum += c - '0';
	}
	string ans;
	while(sum >= 9)
	{
		sum -= 9;
		ans = "9" + ans;
	}
	if(sum > 0) ans = to_string(sum) + ans;
	if(ans == s)
	{
		if(ans[0] == '9')
		{
			ans = '1' + ans;
			ans[1]--;
		}
		else
		{
			ans[0]++;
			ans[1]--;
		}
	}
	cout << ans << endl;
	return 0;
}
