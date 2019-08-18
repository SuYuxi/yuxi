class Solution {
public:
	string lastSubstring(string s) {
		int i = 0;
		int	len = 0; 
		for (auto j = 1; j < s.size(); ++j)
		{
			for (len = 0; j + len < s.size(); ++len) {
				if(s[i + len] != s[j + len])
				{
					i = s[j + len] > s[i + len] ? j : i;
					break;
				}
			}
			if(j + len == s.size()) break;
		}
		return s.substr(i);
	}
};

//fastest but only works for short text
class Solution {
public:
    string lastSubstring(string s) {
		long double mx = 0, pre = 0;
		int inx = 0;
		for(int i = s.size() - 1; i >= 0; i--)
		{
			long double cur = (pre / 26) + s[i] - 'a';
			if(cur > mx)
			{
				mx = cur;
				inx = i;
			}
			pre = cur;
		}
		return s.substr(inx);
	}
};
