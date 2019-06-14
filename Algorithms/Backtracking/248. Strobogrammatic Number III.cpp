//recursion
class Solution {
public:
	int strobogrammaticInRange(string low, string high) {
		int ans = 0;
		long h = stol(high), l = stol(low);
		for(int n = low.size(); n <= high.size(); n++)
		{
			vector<string> v = helper(n, n);
			for(string& s : v)
			{
				long n = stol(s);
				if(n <= h && n >= l) ans++; 
			}
		}
		return ans;
    }
	
	vector<string> helper(int m, int n) {
		if(m == 0) return {""};
		if(m == 1) return {"0", "1", "8"};
		vector<string> v = helper(m - 2, n);
		vector<string> res;
		for(string& s : v)
		{
			if(m != n) res.emplace_back("0" + s + "0");	
			res.emplace_back("1" + s + "1");	
			res.emplace_back("8" + s + "8");	
			res.emplace_back("9" + s + "6");	
			res.emplace_back("6" + s + "9");	
		}
		return res;
	}
};


class Solution {
public:
	int strobogrammaticInRange(string low, string high) {
		if(low.empty() || high.empty() || low.size() > high.size() || (low.size() == high.size() && high.compare(low) < 0)) return 0;
		int count = 0;
		for(int i = low.size(); i <= high.size(); i++)
		{
			string s = string(i, ' ');
			count += helper(low, high, s, 0, i - 1);
		}
		return count;
	}

	int helper(string& low, string& high, string& s, int left, int right) {
		if(left > right)
		{
			if((s.size() == low.size() && s.compare(low) < 0) || s.size() == high.size() && s.compare(high) > 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		int count = 0;
		for(pair<const char, char>& p : pairs)
		{
			s[left] = p.first;
			s[right] = p.second;
			if(s.size() != 1 && s[0] == '0') continue;
			if(left == right && (p.first == '6' || p.first == '9')) continue;
			count += helper(low, high, s, left + 1, right - 1);
		}
		return count;
	}

private:
	unordered_map<char, char> pairs = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
};
