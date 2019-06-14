class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& A, int target) {
		int m = A.size(), n = A[0].size();
		for(int i = 0; i < m; i++)
		{
			for(int j = 1; j < n; j++)
			{
				A[i][j] += A[i][j - 1];	
			}
		}

		int ans = INT_MIN;
		set<int> cnt;
		set<int>::iterator it;
		for(int i = 0; i < n; i++)
		{
			for(int j = i; j < n; j++)
			{
				int cur = 0;
				cnt = {0};
				for(int k = 0; k < m; k++)
				{
					cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
					it = cnt.lower_bound(cur - target);
					if(it != cnt.end()) ans = max(ans, cur - *it);
					cnt.insert(cur);
				}
			}
		}
		return ans;
    }
};
