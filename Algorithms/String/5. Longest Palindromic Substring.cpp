//Manacher's Algorithm
class Solution {
public:
    string longestPalindrome(string s) {
		string str(s.size() * 2 + 3, '#');
		str[0] = '$';
		str.back() = '&';
		int i = 2;
		for(char& c : s)
		{
			str[i] = c;
			i += 2;
		}

		int center = 0, right = 0;
		vector<int> radius(str.size(), 0);

		for(int i = 1; i < str.size() - 1; i += 1)
		{
			if(i < right)
			{
				radius[i] = min(radius[center * 2 - i], right - i);
			}
			while(str[i + radius[i] + 1] == str[i - radius[i] - 1])
			{
				radius[i] += 1;
			}
			if(i + radius[i] > right)
			{
				center = i;
				right = i + radius[i];
			}
		}

		string ans;
		int longest = 0;
		center = 0;
		for(int i = 1; i < radius.size() - 1; i += 1)
		{
			if(radius[i] > longest)
			{
				longest = radius[i];
				center = i;
			}
		}
		// radius equals to (longest) and start pos equals to (center - longest)/2 in original string.
		ans = s.substr((center - longest) / 2,longest);
		return ans;
    }
};
