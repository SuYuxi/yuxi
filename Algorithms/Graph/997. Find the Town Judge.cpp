class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
		vector<int> count(N + 1, 0);
		for(int inx = 0; inx < trust.size(); inx += 1)
		{
			count[trust[inx][1]] += 1;
			count[trust[inx][0]] -= 1;
		}

		for(int inx = 1; inx < count.size(); inx += 1)
		{
			if(count[inx] == N - 1) return inx;
		}
		return -1;
    }
};
