//Greedy
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
		sort(clips.begin(), clips.end(),
			[](const vector<int>& a, const vector<int>& b)
			{
				return a[0] < b[0];
			}
		);
		int res = 0;
		int end1 = -1, end2 = 0; //end1 is last choosed clip and end2 is assumptive choosed clip
		for(vector<int>& clip : clips)
		{
			if(clip[0] > end2 || end2 >= T)
			{
				break;
			}
			else if(clip[0] > end1 && clip[0] <= end2)
			{
				res += 1;
				end1 = end2;
			}
			end2 = max(end2, clip[1]); //clip[0] < end1
		}
		return end2 >= T ? res : -1;
	}
};

//DP
const int INF = 1e9;
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
		sort(clips.begin(), clips.end(),
			[](const vector<int>& a, const vector<int>& b)
			{
				return a[1] < b[1];
			}
		);
		vector<int> dp(clips.size(), INF); //dp[i] represents minimum num of clips to cover from 0 to clips[i][1]
		for(int i = 0; i < clips.size(); i += 1)
		{
			if(clips[i][0] == 0) dp[i] = 1;
			for(int j = 0; j < i; j += 1)
			{
				if(clips[j][1] >= clips[i][0])
				{
					dp[i] = min(dp[i], dp[j] + 1);
				}
			}
		}

		int res = INF;
		for(int i = 0; i < clips.size(); i += 1)
		{
			if(clips[i][1] >= T)
			{
				res = min(res, dp[i]);
			}
		}
		return res == INF ? -1 : res;
    }
};
