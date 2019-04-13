#include <iostream>
using namespace std;
int main()
{
	int A, B;
	cin >> A >> B;
	int ans;
	if(A > B)
	{
		ans = A + (A - 1);
	}
	else if(A < B)
	{
		ans = B + (B - 1);
	}
	else
	{
		ans = A + B;
	}
	cout << ans << endl;
	return 0;
}
