#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int> H(N);
	for(int i = 0; i < N; i += 1) cin >> H[i];
	int border = H[0];
	int cnt = 0;
	for(int& height : H)
	{
		if(height >= border)
		{
			cnt += 1;
			border = height;
		}
	}
	cout << cnt << endl;
	return 0;
}

