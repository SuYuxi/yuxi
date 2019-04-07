#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;
int main()
{
	long long X, Y, Z, K;
	cin >> X >> Y >> Z >> K;
	vector<long long> A(X, 0);
	vector<long long> B(Y, 0);
	vector<long long> C(Z, 0);

	for(int i = 0; i < X; i += 1) cin >> A[i];
	for(int i = 0; i < Y; i += 1) cin >> B[i];
	for(int i = 0; i < Z; i += 1) cin >> C[i];

	sort(A.begin(), A.end(), greater<long long>());
	sort(B.begin(), B.end(), greater<long long>());
	sort(C.begin(), C.end(), greater<long long>());

	K = min(K, X * Y * Z);
	vector<long long> res;

	for(int i = 0; i < X; i += 1)
	{
		for(int j = 0; j < Y; j += 1)
		{
			for(int k = 0; k < Z; k += 1)
			{
				if((i + 1) * (j + 1) * (k + 1) <= K)
					res.emplace_back(A[i] + B[j] + C[k]);	
				else
					break;
			}
		}
	}
	sort(res.begin(), res.end(), greater<long long>());
	for(int i = 0; i < K; i += 1)
	{
		cout << res[i] << endl;
	}

	return 0;
}

//priority queue
//slow
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;
int main()
{
	auto cmp = [](const vector<long long>& a, const vector<long long>& b) {return a[0] < b[0];};
	priority_queue<vector<long long>, vector<vector<long long>>, decltype(cmp) > heap(cmp);
	long long X, Y, Z, K;
	cin >> X >> Y >> Z >> K;
	vector<long long> A(X, 0);
	vector<long long> B(Y, 0);
	vector<long long> C(Z, 0);

	for(int i = 0; i < X; i += 1) cin >> A[i];
	for(int i = 0; i < Y; i += 1) cin >> B[i];
	for(int i = 0; i < Z; i += 1) cin >> C[i];

	sort(A.begin(), A.end(), greater<long long>());
	sort(B.begin(), B.end(), greater<long long>());
	sort(C.begin(), C.end(), greater<long long>());

	vector<vector<vector<bool>>> flags(X, vector<vector<bool>>(Y, vector<bool>(Z, false)));

	int i, j, k;
	heap.emplace(vector<long long>({A[0] + B[0] + C[0], 0, 0, 0}));
	flags[0][0][0] = true;
	for(int t = 0; t < K; t += 1)
	{
		cout << heap.top()[0] << endl;
		i = heap.top()[1], j = heap.top()[2], k = heap.top()[3];
		heap.pop();
		if(i + 1 < X && !flags[i + 1][j][k])
		{
			heap.emplace(vector<long long>({A[i + 1] + B[j] + C[k], i + 1, j, k}));
			flags[i + 1][j][k] = true;
		}
		if(j + 1 < Y && !flags[i][j + 1][k])
		{
			heap.emplace(vector<long long>({A[i] + B[j + 1] + C[k], i, j + 1, k}));
			flags[i][j + 1][k] = true;
		}
		if(k + 1 < Z && !flags[i][j][k + 1])
		{
			heap.emplace(vector<long long>({A[i] + B[j] + C[k + 1], i, j, k + 1}));
			flags[i][j][k + 1] = true;
		}
	}
	return 0;
}

//Binary search
//slow

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool solve(long long P, int X, int Y, int Z, int K, vector<long long>& A, vector<long long>& B, vector<long long>& C)
{
	int cnt = 0;
	for(int i = 0; i < X; i += 1)
	{
		for(int j = 0; j < Y; j += 1)
		{
			for(int k = 0; k < Z; k += 1)
			{
				if(A[i] + B[j] + C[k] < P) break;
				cnt += 1;
				if(cnt >= K) return true;
			}
		}
	}
	return false;
}

int main()
{
	int X, Y, Z, K;
	cin >> X >> Y >> Z >> K;
	vector<long long> A(X, 0);
	vector<long long> B(Y, 0);
	vector<long long> C(Z, 0);

	for(int i = 0; i < X; i += 1) cin >> A[i];
	for(int i = 0; i < Y; i += 1) cin >> B[i];
	for(int i = 0; i < Z; i += 1) cin >> C[i];

	sort(A.begin(), A.end(), greater<long long>());
	sort(B.begin(), B.end(), greater<long long>());
	sort(C.begin(), C.end(), greater<long long>());

	K = min(K, X * Y * Z);
	long long Max = A[0] + B[0] + C[0], Min = A[X-1] + B[Y-1] + C[Z-1];
	while(Min < Max)
	{
		long long Mid = Min + ((Max - Min - 1) / 2) + 1;
		if(solve(Mid, X, Y, Z, K, A, B, C))
		{
			Min = Mid;
		}
		else
		{
			Max = Mid - 1;
		}
	}
	int P = Min;
	vector<long long> res;

	for(int i = 0; i < X; i += 1)
	{
		for(int j = 0; j < Y; j += 1)
		{
			for(int k = 0; k < Z; k += 1)
			{
				if(A[i] + B[j] + C[k] < P) break;
				res.emplace_back(A[i] + B[j] + C[k]);
			}
		}
	}

	sort(res.begin(), res.end(), greater<long long>());
	for(int i = 0; i < K; i += 1)
	{
		cout << res[i] << endl;
	}

	return 0;
}
