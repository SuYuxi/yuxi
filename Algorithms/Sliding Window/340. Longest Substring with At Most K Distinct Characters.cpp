//ordered_map by Least recently used cache
class Solution {
typedef list<char> LI;
typedef pair<int, LI::iterator> PIL;
typedef unordered_map<char, PIL> UCPIL;

public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
		int len = s.size();
		if(k <= 0 || len == 0) return 0;

		UCPIL cache;
		LI pList;

		int l = 0, r = 0;
		int ans = 0;
		while(r < len)
		{
			char key = s[r];
			UCPIL::iterator it = cache.find(key);
			if(it == cache.end())
			{
				pList.emplace_front(key);
			}
			else
			{
				pList.erase(it->second.second);
				pList.emplace_front(key);
			}
			cache[key] = {r, pList.begin()};

			if(pList.size() > k)
			{
				l = cache[pList.back()].first + 1;
				cache.erase(pList.back());
				pList.pop_back();
			}
			r++;
			ans = max(ans, r - l);
		}
		return ans;
    }
};

//sliding window
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
		int len = s.size();
		if(k <= 0 || len == 0) return 0;
		unordered_map<char, int> hash;
		int cnt = 0; // distinct characters
		int l = 0, r = 0;
		int ans = 0;
		while(r < len)
		{
			hash[s[r]]++;
			if(hash[s[r]] == 1) cnt++;
			r++;
			while(l < r && cnt > k)
			{
				hash[s[l]]--;
				if(hash[s[l]] == 0) cnt--;
				l++;
			}
			ans = max(ans, r - l);
		}
		return ans;
    }
};
