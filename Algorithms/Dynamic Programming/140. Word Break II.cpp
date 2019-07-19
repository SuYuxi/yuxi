class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
		wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
		return dfs(s, wordSet, 0);
    }
private:
	unordered_map<int, vector<string>> dict; //<startIndex, stringList>
	unordered_set<string> wordSet;

	vector<string> dfs(string& s, unordered_set<string>& wordSet, int start) {
		if(dict.count(start)) return dict[start];
		vector<string> res;
		if(start == s.size()) res.emplace_back("");
		for(int end = start; end < s.size(); end++)
		{
			if(wordSet.count(s.substr(start, end - start + 1)))
			{
				vector<string> list = dfs(s, wordSet, end + 1);
				for(string& l : list)
				{
					res.emplace_back(s.substr(start, end - start + 1) + (l == "" ? "" : " ") + l);
				}
			}
		}
		dict[start] = res;
		return res;
	}
};
