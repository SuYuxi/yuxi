class Solution {
public:
    bool repeatedSubstringPattern(string s) {
		string ss = (s + s).substr(1, s.size() * 2 - 2);
		return ss.find(s) != string::npos;
    }
};
