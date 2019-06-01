class Solution {
public:
    int assignBikes(vector<vector<int>>& A, vector<vector<int>>& B) {
		this->A = A;
		this->B = B;
		m = A.size();
		n = B.size();
		return dfs(0, (1 << n) - 1);
    }
private:
	vector<vector<int>> A, B;	
	int ans;
	int m, n;
	int dfs(int pos, int mask) {
		if(pos == m) return 0;
		int ret = INT_MAX;

		for(int i = 0; i < n; i++)
		{
			if(mask & (1 << i))
			{
				int dist = getDist(pos, i);
				ret = min(ret, dist + dfs(pos + 1, mask ^ (1 << i)));
			}
		}
		return ret;
	}
	int getDist(int i, int j) {
		return abs(A[i][0] - B[j][0]) + abs(A[i][1] - B[j][1]);
	}
};
