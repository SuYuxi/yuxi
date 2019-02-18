class Solution {
public:
    bool isIsomorphic(string s, string t) {
		std::map<char, char> dict;
		std::unordered_set<char> set;
		for(int inx = 0; inx < s.size(); inx++)
		{
			if(dict.count(s[inx]) == 0)
			{
				if(set.count(t[inx]) == 0)
				{
					dict[s[inx]] = t[inx];
					set.insert(t[inx]);
				}
				else return false;
			}
			else
			{
				if(dict[s[inx]] != t[inx]) return false;
			}
		}
		return true;
	}
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		char smap[128] = {};
		char tmap[128] = {};
		if(s.size() != t.size()) return false;
		for(int inx = 0; inx < s.size(); inx++)
		{
			if(smap[s[inx]] != tmap[t[inx]])
			{
				return false;
			}
			else
			{
				smap[s[inx]] = t[inx];
				tmap[t[inx]] = t[inx];
			}
		}

		return true;
	}
};
