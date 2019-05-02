#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> s(26);
	for(int& num : s)
	{
		cin >> num;
	}
	vector<string> dict = {"", "a", "aa", "aaa", "aaai", "aaaji", "aabaji", "daabaji", "dagabaji"};
	cout << s[0] - s[1] << endl; // A - B
	cout << s[2] + s[3] << endl; // C + D
	cout << s[4] > s[5] ? 0 : s[5] + 1 - s[4] << endl; // E + 1 - D 
	cout << (s[6] + s[7] + s[8]) / 3 + 1 << endl; // (G + H + I) / 3 + 1
	cout << dict[s[9]] << endl; // dict[J]
	int vector<int> like = {s[10] % 59, L = s[11] % 61}
	cout << 6 << endl; // perfect number
	int mod = 9973;
	cout << ((s[14] + s[15] + s[16]) % mod) * ((s[17] + s[18] + s[19]) % mod) * ((s[20] + s[21] + s[22]) % mod) * ((s[23] + s[24] + s[25]) % mod)) % mod << endl; //(O + P + Q)(R + S + T)(U + V + W)(X + Y + Z) % mod
	return 0;
}
