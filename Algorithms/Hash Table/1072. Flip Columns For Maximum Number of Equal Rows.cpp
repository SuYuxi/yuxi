class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		unordered_map<string, int> hash;
		int ans = 0;
		for(vector<int>& v : matrix)
		{
			string s;	
			string inv;	
			for(int& i : v)
			{
				s.push_back('0' + i);
				inv.push_back('0' - (i ^ 1));
			}
			hash[s]++;
			hash[inv]++;
			ans = max(ans, max(hash[s], hash[inv]));
		}
		return ans;
    }
};
