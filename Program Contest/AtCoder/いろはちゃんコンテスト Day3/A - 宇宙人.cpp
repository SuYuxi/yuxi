#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	vector<long long> s(26);
	for(long long& num : s)
	{
		cin >> num;
	}
	vector<string> dict = {"", "a", "aa", "aaa", "aaai", "aaaji", "aabaji", "agabaji", "dagabaji"};
	cout << s[0] - s[1] << endl; // A - B
	cout << s[2] + s[3] << endl; // C + D
	cout << (s[4] > s[5] ? 0 : s[5] + 1 - s[4]) << endl; // E + 1 - D 
	cout << (s[6] + s[7] + s[8]) / 3 + 1 << endl; // (G + H + I) / 3 + 1
	cout << dict[s[9]] << endl; // dict[J]
	int num1 = 1;
	while(num1 % 59 != s[10] || num1 % 61 != s[11])
	{
		num1++;
	}
	num1 += 59 * 61 * (s[12] - 1);
	vector<int> perfectNum = {6, 28, 496, 8128};
	int num2;
	for(int& i : perfectNum)
	{
		if(abs(num1 - i) >= s[13])
		{
			num2 = i;
			break;
		}
	}
	cout << min(num1, num2) << endl;
	cout << max(num1, num2) << endl;
	int mod = 9973;
	cout << (((s[14] + s[15] + s[16]) % mod) * ((s[17] + s[18] + s[19]) % mod) * ((s[20] + s[21] + s[22]) % mod) * ((s[23] + s[24] + s[25]) % mod)) % mod << endl; //(O + P + Q)(R + S + T)(U + V + W)(X + Y + Z) % mod
	return 0;
}
