class Solution {
    public int countNegatives(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        int r = 0, c = w - 1;
        int res = 0;
        while(r < h && c>= 0) {
            if(grid[r][c] < 0) {
                c -= 1;
                res += h - r;
            }
            else {
                r += 1;
            }
        }
        return res;
    }
}
