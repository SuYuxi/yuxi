//greedy
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> ans;
	for(int i = 2; i * i <= N && ans.size() != K - 1;)
	{
		if(N % i == 0)
		{
			N /= i;
			ans.emplace_back(i);
		}
		else
		{
			i++;
		}
	}
	ans.emplace_back(N);
	if(ans.size() == K)
	{
		cout << ans[0];
		for(int i = 1; i < ans.size(); i++)
		{
			cout << " " << ans[i];
		}
		cout << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
	return 0;
}
