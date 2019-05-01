#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int N, X, Y;
	cin >> N >> X >> Y;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end(), greater<int>());
	for(int i = 0; i < N; i++)
	{
		if(i % 2 == 0)
		{
			X += A[i];
		}
		else
		{
			Y += A[i];
		}
	}
	if(X > Y)
	{
		cout << "Takahashi" << endl;
	}
	else if(X < Y)
	{
		cout << "Aoki" << endl;
	}
	else
	{
		cout << "Draw" << endl;
	}
	return 0;
}
