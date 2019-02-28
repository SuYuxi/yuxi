class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	vector<int> hash(128, 0);
	int left = 0, right = 0, count = 0, window = 0;
	while(right < s.size())
	{
		if(hash[s[right++]]++ == 1) count += 1;
		while(count > 0)
		{
			if(hash[s[left++]]-- == 2) count -= 1;	
		}
		window = max(window, right - left);
	}
	return window;
    }
};
