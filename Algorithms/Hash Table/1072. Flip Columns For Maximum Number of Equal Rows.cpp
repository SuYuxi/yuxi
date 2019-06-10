class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		unordered_map<string, int> hash;
		int ans = 0;
		for(vector<int>& v : matrix)
		{
			string s;	
			for(int& i : v)
			{
				s.push_back('0' + (i ^ v[0]));
			}
			hash[s]++;
			ans = max(ans, hash[s]);
		}
		return ans;
    }
};
