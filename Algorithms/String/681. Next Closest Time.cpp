class Solution {
public:
    string nextClosestTime(string time) {
		int hour = stoi(time.substr(0, 2));
		int minute = stoi(time.substr(3, 2));
		int MOD = 24 * 60;
		int start = hour * 60 + minute;
		int elapsed = MOD;
		int ans = start;
		unordered_set<int> digits = {hour % 10, hour / 10, minute % 10, minute / 10}; 
		for(const int& h1: digits)
		{
			for(const int& h2: digits)
			{
				for(const int& m1: digits)
				{
					for(const int& m2: digits)
					{
						int h = h1 * 10 + h2;	
						int m = m1 * 10 + m2;
						if(h < 24 && m < 60)
						{
							int cur = 60 * h + m;
							int curElapsed = (cur - start + MOD) % MOD;
							if(curElapsed > 0 && curElapsed < elapsed)
							{
								elapsed = curElapsed;
								ans = cur;
							}
						}
					}
				}
			}
		}
		string res;
		if(ans / 60 < 10) res += "0";
		res += to_string(ans / 60) + ":";
		if(ans % 60 < 10) res += "0";
		res += to_string(ans % 60);
		return res;
    }
};
