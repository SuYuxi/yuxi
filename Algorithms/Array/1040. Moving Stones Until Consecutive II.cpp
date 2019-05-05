const int INF = 1e9;
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
		sort(stones.begin(), stones.end());
		int n = stones.size();
		int Min = INF, Max = 0;
		Max = max(stones[n - 1] - stones[1] + 2 - n, stones[n - 2] - stones[0] + 2 - n);
		for(int i = 0; i < n; i++)
		{
			int j = i;
			while(j + 1 < n && stones[j + 1] - stones[i] < n)
			{
				j++;
			}
			if(j - i + 1 == n - 1 && stones[j] - stones[i] == n - 2)
			{
				Min = min(Min, 2);
			}
			else
			{
				Min = min(Min, n - (j - i + 1));
			}
		}
		return { Min, Max };
    }
};
