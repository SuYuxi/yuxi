#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int Inf = 1e9;
int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());
	if(A[1] == 1)
	{
		cout << "1"<< endl;
		return 0;
	}
	
	for(int num = A[1]; num >= 1; num--)
	{
		int cnt = 0;
		for(int i = 0; i < N; i++)
		{
			if(A[i] % num != 0)
			{
				cnt++;
				if(cnt > 1) break;
			}
		}
		if(cnt <= 1)
		{
			cout << num << endl;
			return 0;
		}
	}
	cout << "1"<< endl;
	return 0;
}

//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int x, int y)
{
	int t = 1;
	while(t != 0)
	{
		t = x % y;
		x = y;
		y = t;
	}
	return x;
}

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> L(N+1), R(N+1);
	L[0] = 0, R[N] = 0;
	L[1] = A[0], R[N - 1] = A[N - 1];
	for(int i = 2; i < N + 1; i++)
	{
		L[i] = gcd(A[i - 1], L[i - 1]);	
	}
	for(int i = N - 2; i >= 0; i--)
	{
		R[i] = gcd(A[i], R[i + 1]);
	}
	int maxGCD = max(L[N - 1], R[1]);
	for(int i = 1; i < N - 1; i++)
	{
		maxGCD = max(maxGCD, gcd(L[i], R[i + 1]));
	}
	cout << maxGCD << endl;
	return 0;
}
