class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
		return helper(n, n);
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
