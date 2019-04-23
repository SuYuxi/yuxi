#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	string S;
	cin >> N >> S;
	int white = 0; 
	for(char& c : S)
	{
		if(c == '.') white++;
	}
	int rightWhite = white;
	int leftBlack = 0;
	int ans = white;
	for(int inx = 0; inx < N; inx++)
	{
		if(S[inx] == '.')
		{
			rightWhite--;
		}
		else
		{
			leftBlack++;
		}
		ans = min(ans, leftBlack + rightWhite);
	}
	cout << ans << endl;
	return 0;
}

