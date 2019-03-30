class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false)); 
		for(int end = 0; end < s.size(); end += 1)
		{
			for(int start = 0; start <= end; start += 1)
			{
				if(s[start] == s[end] && ((end - start <= 2) || dp[start + 1][end - 1]))
				{
					dp[start][end] = true;
				}
			}
		}

		vector<vector<string>> res;
		vector<string> subStrings; //to spead up by passing reference
		helper(s, dp, res, subStrings, 0);
		return res;
    }

private:
	void helper(string& s, vector<vector<bool>>& dp, vector<vector<string>>& res, vector<string>& subStrings, int startPos) {
		if(startPos == s.size())
		{
			res.emplace_back(subStrings);
			return;
		}

		for(int inx = startPos; inx < s.size(); inx += 1)
		{
			if(dp[startPos][inx])
			{
				subStrings.emplace_back(s.substr(startPos, inx - startPos + 1));
				helper(s, dp, res, subStrings, inx + 1);
				subStrings.pop_back();
			}
		}
	}
};
