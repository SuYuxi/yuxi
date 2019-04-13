//short version
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int ans = s.size();

	for(int i = 0; i < 2; i++)
	{
		int cnt = 0;
		for(int j = 0; j < s.size(); j += 1)
		{
			if((j % 2 == 0) ^ (s[j] == char(i + '0'))) cnt++;
		}
		ans = min(ans, cnt);
	}

	cout << ans << endl;
	return 0;
}

//full version
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	int oddBlack = 0, evenBlack = 0;
	int oddWhite = 0, evenWhite = 0;

	for(int i = 0; i < s.size(); i += 1)
	{
		if(i % 2 == 1)
		{
			if(s[i] == '1')
			{
				oddWhite += 1;
			}
			else
			{
				oddBlack += 1;
			}
		}
		else
		{
			if(s[i] == '1')
			{
				evenWhite += 1;
			}
			else
			{
				evenBlack += 1;
			}
		}
	}
	cnt = min(oddWhite + evenBlack, oddBlack + evenWhite);

	cout << cnt << endl;
	return 0;
}
