//better way
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	int N, K;
	string s;	
	cin >> N >> K;
	cin >> s;
	vector<int> nums;
	int now = 1, cnt = 0;
	for(char& c : s)
	{
		if(c == char(now + '0')) cnt++;
		else
		{
			nums.emplace_back(cnt);
			cnt = 1;
			now ^= 1;
		}
	}
	if(cnt != 0) nums.emplace_back(cnt);

	if(nums.size() % 2 == 0) nums.emplace_back(0);
	int length = K * 2 + 1;

	int left = 0, right = 0;
	int sum = 0, ans = 0;
	for(int i = 0; i < nums.size(); i += 2)
	{
		int nextL = i;
		int nextR = min(nextL + length, (int)nums.size());
		while(left < nextL)
		{
			sum -= nums[left];
			left++;
		}
		while(right < nextR)
		{
			sum += nums[right];
			right++;
		}
		ans = max(ans, sum);
	}

	cout << ans << endl;
	return 0;
}

//Easier to meet bugs
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int main()
{
	int N, K;
	string s;	
	cin >> N >> K;
	cin >> s;
	int ans = 1;
	int cnt = (s[0] == '0') ? 1 : 0;
	queue<int> q({0}); //store start inx of '1' in queue
	int inx = 1;
	while(inx < N)
	{
		while(inx < N)
		{
			if(s[inx] == '0' && s[inx-1] == '1')
			{
				cnt++;
				if(cnt > K)
				{
					cnt--;
					break;
				}
			}
			else if(s[inx] == '1' && s[inx-1] == '0')
			{
				q.emplace(inx);
			}
			inx++;
		}
		ans = max(ans, inx - q.front());
		q.pop();
		inx++;
	}

	cout << ans << endl;
	return 0;
}
