class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        vector<int> peoples(41, 0);
        for(int i = 0; i < hats.size(); ++i)
        {
            for(int& hat : hats[i])
            {
                peoples[hat] |= (1 << i);
            }
        }
        vector<vector<int>> dp(41, vector<int>(1024, -1));
        return backtrack(peoples, dp, hats.size(), 0, 1);
    }
    
    int backtrack(vector<int>& peoples, vector<vector<int>>& dp, int people, int hash, int inx) {
        if(inx > 40)
        {
            return (hash == (1 << people) - 1) ? 1 : 0;
        }
        if(dp[inx][hash] != -1)
        {
            return dp[inx][hash];
        }
        int number = backtrack(peoples, dp, people, hash, inx + 1);
        for(int p = 0; p < people; ++p)
        {
            if(hash & (1 << p)) continue;
            if(peoples[inx] & (1 << p))
            {
                number += backtrack(peoples, dp, people, hash | (1 << p), inx + 1);
                number %= mod;
            }
        }
        dp[inx][hash] = number;
        return dp[inx][hash];
    }
private:
    int mod = 1e9 + 7;
};
