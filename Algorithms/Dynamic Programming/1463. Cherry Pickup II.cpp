class Solution {
public:
    int dp[70][70][70];
    int cherryPickup(vector<vector<int>>& grid) {
        h = grid.size();
        w = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return dfs(grid, 0, 0, w - 1);
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c1, int c2) {
        if(r == h) return 0;
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        int cherry = 0;
        for(int nc1 = c1 - 1; nc1 <= c1 + 1; ++nc1)
        {
            for(int nc2 = c2 - 1; nc2 <= c2 + 1; ++ nc2)
            {
                if(nc1 >= 0 && nc1 < w && nc2 >= 0 && nc2 < w)
                {
                    cherry = max(cherry, dfs(grid, r + 1, nc1, nc2)); 
                }
            }
        }
        cherry += (c1 == c2) ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        dp[r][c1][c2] = cherry;
        return cherry;
    }
private:
    int h, w;
};
