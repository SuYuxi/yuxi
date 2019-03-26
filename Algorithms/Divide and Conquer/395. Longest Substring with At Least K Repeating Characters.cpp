//brief but slow
class Solution {
public:
    int longestSubstring(string s, int k) {
		return longest(s, 0, s.size(), k);
    }

private:
	int longest(string& s, int left, int right, int k)
	{
		vector<int> count(26, 0);
		for(int inx = left; inx < right; inx += 1)
		{
			count[s[inx] - 'a'] += 1;
		}
		for(int inx = left; inx < right; inx += 1)
		{
			if(count[s[inx] - 'a'] < k)
			{
				return max(longest(s, left, inx, k), longest(s, inx + 1, right, k));
			}
		}
		return right - left;
	}
};


//fastest
class Solution {
public:
    int longestSubstring(string s, int k) {
		map<char, int> sDict;
		for(char& c : s)
		{
			sDict[c] += 1;
		}
		int left = 0, Max = 0;
		for(int inx = 0; inx < s.size(); inx += 1)
		{
			if(sDict[s[inx]] < k)
			{
				Max = max(Max, longestSubstring(s.substr(left, inx - left), k));
				while(left <= inx)
				{
					sDict[s[left]] -= 1;
					left += 1;
				}
			}
		}
		return max(Max, int(s.size()) - left);
    }
};
