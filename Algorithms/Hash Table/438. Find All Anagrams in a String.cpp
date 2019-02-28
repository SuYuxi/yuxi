class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		if(s.empty() || p.empty()) return res;
		vector<int> hash(256, 0);
		int left = 0, right = 0, count = p.size();
		for(char& c : p)
		{
			hash[c] += 1;
		}
		while(right < s.size())
		{
			if(hash[s[right++]]-- > 0) count -= 1;
			if(count == 0) res.emplace_back(left);	
			if(right - left == p.size() && hash[s[left++]]++ >= 0) count += 1;
		}
		return res;
    }
};
