class Solution {
public:
    int longestStrChain(vector<string>& words) {
		vector<unordered_map<string, int>> lenHash(1000);
		int len = INT_MAX;
		for(string& word : words)
		{
			lenHash[word.size()][word] = 1;
			len = min(len, (int)word.size());
		}
		bool next = true;
		int ans= 1;
		while(next)
		{
			next = false;	
			for(auto& s : lenHash[len])
			{
				for(auto& p: lenHash[len + 1])
				{
					if(check(s.first, p.first))
					{
						next = true;
						p.second = max(p.second, s.second + 1);
						ans = max(ans, p.second); 
					}
				}
			}
			len++;
		}
		return ans;
    }

private:
	bool check(string s, string p) {
		if(s.size() + 1 != p.size()) return false;
		for(int i = 0, j = 0; i < s.size();)
		{
			if(s[i] == p[j])
			{
				i++;
				j++;
			}
			else
			{
				if(j - i >= 1) return false;
				j++;
			}
		}
		return true;
	}
};
