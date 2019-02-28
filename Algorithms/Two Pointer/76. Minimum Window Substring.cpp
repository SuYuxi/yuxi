class Solution {
public:
    string minWindow(string s, string t) {
		int left = 0, right = 0, head = 0, window = INT_MAX, count = t.size();
		string res;
		vector<int> hash(256, 0);
		for(char& c : t)
		{
			hash[c] += 1;
		}
		while(right < s.size())
		{
			if(hash[s[right++]]-- > 0) count--;
			while(count == 0) 
			{
				if(right - left < window)
				{
					window = right - left;
					head = left;
				}
				if(hash[s[left++]]++ == 0) count++;
			}
		}
		return window == INT_MAX ? string() : s.substr(head, window);
    }
};
