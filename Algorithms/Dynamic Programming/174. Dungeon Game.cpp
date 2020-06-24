class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty()) return 1;
        int rows = dungeon.size(), cols = dungeon[0].size();
        vector<int> dp(cols);
        for(int r = rows - 1; r >= 0; --r)
        {
            for(int c = cols - 1; c >= 0; --c)
            {
                if(r == rows - 1 && c == cols - 1)
                {
                    dp[c] = max(0, -dungeon[r][c]);
                }
                else if(r == rows - 1)
                {
                    dp[c] = max(0, dp[c + 1] - dungeon[r][c]);
                }
                else if(c == cols - 1)
                {
                    dp[c] = max(0, dp[c] - dungeon[r][c]);
                }
                else
                {
                    dp[c] = max(0, min(dp[c], dp[c + 1]) - dungeon[r][c]);  
                }
            }
        }
        return dp[0] + 1;
    }
};
