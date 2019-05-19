//consider signl symbols + - infront of each weight
//knapsack problem
//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
#include <unordered_set>
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
		unordered_set<int> dp = {0};
		int Sum = 0;
		for(int& stone : stones)
		{
			Sum += stone;
			unordered_set<int> temp(dp);
			for(const int& i : temp)
			{
				dp.insert(i + stone);
			}
		}
		int res = INT_MAX;
		for(const int& i : dp)
		{
			res = min(res, abs(Sum - i * 2));
		}
		return res;
	}
};

#include <bitset>
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
		bitset<3000> dp {1};	
		int Sum = 0;
		for(int& stone : stones)
		{
			Sum += stone;
			for(int j = dp.size() - 1; j >= stone; j--)
			{
				dp[j] = dp[j] | dp[j - stone];
			}
		}
		int res = INT_MAX;
		for(int i = 0; i < dp.size(); i++)
		{
			if(dp[i])
			{
				res = min(res, abs(Sum - dp[i] * i * 2));
			}
		}
		return res;
	}
};

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
		if(stones.empty()) return 0;
		int size = stones.size();
		dp.resize(30);

		return min(abs(dfs(stones, 1, stones[0])), abs(dfs(stones, 1, -stones[0])));
    }

private:
	vector<unordered_map<int, int>> dp;

	int dfs(vector<int>& stones, int inx, int curSum) {
		if(inx == stones.size()) return curSum;
		if(dp[inx].count(curSum)) return dp[inx][curSum];
		return dp[inx][curSum] = min(abs(dfs(stones, inx + 1, curSum + stones[inx])), abs(dfs(stones, inx + 1, curSum - stones[inx])));
	}
};
