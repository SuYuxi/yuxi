class Solution {
    public int orangesRotting(int[][] grid) {
        int day = 0, fresh = 0;
        for(int i = 0; i < grid.length; ++i) {
            for(int j = 0; j < grid[0].length; ++j) {
                if(grid[i][j] == 1) ++fresh;
            }
        }
        for(int preFresh = fresh; fresh > 0; ++day, preFresh = fresh) {
            for(int i = 0; i < grid.length; ++i) {
                for(int j = 0; j < grid[0].length; ++j) {
                    if(grid[i][j] == day + 2) fresh -= rot(grid, i + 1, j, day) + rot(grid, i - 1, j, day) + rot(grid, i, j - 1, day) + rot(grid, i, j + 1, day);
                }
            }
            if(fresh == preFresh) return -1;
        }
        return day;
    }
    
    private int rot(int[][] grid, int i, int j, int day) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[i].length || grid[i][j] != 1) return 0;
        grid[i][j] = day + 3;
        return 1;
    }
}
