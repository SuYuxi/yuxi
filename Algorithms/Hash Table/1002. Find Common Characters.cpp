class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
		vector<int> cnt(26, INT_MAX);
		vector<string> res;
		for(string& s : A)
		{
			vector<int> cntS(26, 0);
			for(char& c : s)
			{
				cntS[c - 'a'] += 1;	
			}
			for(int inx = 0; inx < 26; inx += 1)
			{
				cnt[inx] = min(cnt[inx], cntS[inx]);
			}
		}
		for(int inx = 0; inx < 26; inx += 1)
		{
			for(int num = 0; num < cnt[inx]; num += 1)
			{
				res.emplace_back(string(1, 'a' + inx));
			}
		}
		return res;
	}
};
