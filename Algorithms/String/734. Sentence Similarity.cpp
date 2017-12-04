class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
		if (words1.size() != words2.size()) return false;
		map<string, set<string>> hashmap;
		for (pair<string, string> &p : pairs) {
			hashmap[p.first].insert(p.second);
		}
		for (int inx = 0; inx < words1.size(); inx++) {
			string &s1 = words1[inx];
			string &s2 = words2[inx];
			if(s1 != s2 && !hashmap[s1].count(s2) && !hashmap[s2].count(s1)) {
			return false;
			}
		}
		return true;	
	}
};
