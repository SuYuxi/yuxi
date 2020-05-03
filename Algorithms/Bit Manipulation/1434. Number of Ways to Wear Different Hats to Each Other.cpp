//Top->Bottom
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
        return dfs(peoples, dp, hats.size(), 0, 1);
    }
    
    int dfs(vector<int>& peoples, vector<vector<int>>& dp, int people, int hash, int inx) {
        if(inx > 40)
        {
            return (hash == (1 << people) - 1) ? 1 : 0;
        }
        if(dp[inx][hash] != -1)
        {
            return dp[inx][hash];
        }
        int number = dfs(peoples, dp, people, hash, inx + 1);
        for(int p = 0; p < people; ++p)
        {
            if(hash & (1 << p)) continue;
            if(peoples[inx] & (1 << p))
            {
                number += dfs(peoples, dp, people, hash | (1 << p), inx + 1);
                number %= mod;
            }
        }
        dp[inx][hash] = number;
        return dp[inx][hash];
    }
private:
    int mod = 1e9 + 7;
};

//Bottom->Top
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<int> masks(1 << n, 0);
        masks[0] = 1;
        vector<vector<int>> peoples(41);
        for(int p = 0; p < hats.size(); ++p)
        {
            for(int hat : hats[p])
            {
                peoples[hat].emplace_back(p);
            }
        }
        for(int hat = 1; hat < peoples.size(); ++hat)
        {
            for(int mask = (1 << n) - 1; mask >= 0; --mask)
            {
                for(int& p: peoples[hat])
                {
                    if((mask & (1 << p)) == 0)
                    {
                        masks[mask | (1 << p)] += masks[mask];
                        masks[mask | (1 << p)] %= mod;
                    }
                }
            }
        }
        return masks[(1 << n) - 1];
    }

private:
    int mod = 1e9 + 7;
};
