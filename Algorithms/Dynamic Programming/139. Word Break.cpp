class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return dfs(s, wordSet, dp, 0);
    }

private:
    bool dfs(string& s, unordered_set<string>& wordDict, vector<int>& dp, int inx) {
        if(inx == s.size()) return true;
        if(dp[inx] != -1) return dp[inx] == 1;
        string cur;
        for(int i = inx; i < s.size(); i++)
        {
            cur.push_back(s[i]);
            if(wordDict.count(cur) != 0 && dfs(s, wordDict, dp, i + 1))
            {
                dp[inx] = 1139. Word Break;
                return true;
            }
        }
        dp[inx] = 0;
        return false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for(int i = 1; i <= s.size(); i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(dp[j] && wordSet.count(s.substr(j, i - j)))
				{
					dp[i] = true;
					break;
				}
			}
		}
        return dp[s.size()];
    }
};
