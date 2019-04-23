#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	if((C >= min(A, B)) && (C <= max(A, B)))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
