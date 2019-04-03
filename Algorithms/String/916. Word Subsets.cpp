class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		vector<int> maxLetter(26, 0);
		for(string& s : B)
		{
			vector<int>&& cnt = count(s);
			for(int i = 0; i < 26; i += 1)
			{
				maxLetter[i] = max(maxLetter[i], cnt[i]);
			}
		}
		vector<string> res;
		for(string& s : A)
		{
			vector<int>&& cnt = count(s);
			int i = 0;
			while(i < 26 && cnt[i] >= maxLetter[i])
			{
				i += 1;
			}
			if(i == 26)
			{
				res.emplace_back(s);
			}
		}
		return res;
    }

private:
	vector<int> count(string s) {
		vector<int> cnt(26, 0);
		for(char& c : s)
		{
			cnt[c - 'a'] += 1;
		}
		return cnt;
	}
};
