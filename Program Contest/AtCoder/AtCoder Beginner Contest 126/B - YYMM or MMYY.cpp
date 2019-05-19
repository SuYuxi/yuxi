#include <iostream>
#include <string>

using namespace std;
int main()
{
	string S;
	cin >> S;
	int A = stoi(S.substr(0, 2));
	int B = stoi(S.substr(2, 2));
	if(A > 0 && A <= 12)
	{
		if(B > 0 && B <= 12)
		{
			cout << "AMBIGUOUS" << endl;
		}
		else
		{
			cout << "MMYY" << endl;
		}
	}
	else if(B > 0 && B <= 12)
	{
			cout << "YYMM" << endl;
	}
	else
	{
		cout << "NA" << endl;
	}
	return 0;
}
