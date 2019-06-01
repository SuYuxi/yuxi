class Solution {
public:
    vector<vector<int>> indexPairs(string s, vector<string>& words) {
        unordered_set<string> A(words.begin(), words.end());
        int n = s.size();
        vector<vector<int>> ret;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (A.count(s.substr(i, j - i))) {
                    ret.push_back({i, j - 1});
                }
            }
        }
        return ret;
    }
};
