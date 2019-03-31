#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N, Q;
	cin >> N >> Q;
	string s;
	cin >> s;
	vector<char> t(Q);
	vector<char> d(Q);
	for(int i = 0; i < Q; i += 1)
	{
		cin >> t[i] >> d[i];
	}

	int left = 0, right = N - 1;
	for(int i = Q - 1; i >= 0; i -= 1)
	{
		if(s[left] == t[i] && d[i] == 'L')
		{
			left += 1;
		}
		else if(s[right] == t[i] && d[i] == 'R')
		{
			right -= 1;
		}

		if(left > 0 && s[left - 1] == t[i] && d[i] == 'R')
		{
			left -= 1;
		}
		else if(right < N - 1 && s[right + 1] == t[i] && d[i] == 'L')
		{
			right += 1;
		}

		if(left > right)
			break;
	}

	std::cout << std::to_string(right - left + 1) << std::endl;
	return 0;
}

#include <string>
#include <iostream>
#include <vector>

//binary search to get the left and right boundary separately
//easier to understand
using namespace std;
int main()
{
	int N, Q;
	cin >> N >> Q;
	string s;
	cin >> s;
	vector<char> t(Q);
	vector<char> d(Q);
	for(int i = 0; i < Q; i += 1)
	{
		cin >> t[i] >> d[i];
	}

	int L = -1;
	int left = 0, right = N - 1;
	while(left <= right)
	{
		int mid = (left + right) >> 1;
		int inx = mid;
		for(int i = 0; i < Q; i += 1)
		{
			if(s[inx] == t[i])
			{
				if(d[i] == 'L')
					inx -= 1;
				else
					inx += 1;
			}
			if(inx < 0 || inx > N - 1) break;
		}

		if(inx < 0)
		{
			L = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	int R = N; 
	left = 0, right = N - 1;
	while(left <= right)
	{
		int mid = (left + right) >> 1;
		int inx = mid;
		for(int i = 0; i < Q; i += 1)
		{
			if(s[inx] == t[i])
			{
				if(d[i] == 'R')
					inx += 1;
				else
					inx -= 1;
			}
			if(inx < 0 || inx > N - 1) break;
		}

		if(inx > N - 1)
		{
			R = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	std::cout << std::to_string(R - L - 1) << std::endl;

	return 0;
}
