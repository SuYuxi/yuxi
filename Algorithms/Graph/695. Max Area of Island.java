class Solution {
    int w, h;
    boolean[][] visited;
    int area;
    public int maxAreaOfIsland(int[][] grid) {
        if(grid.length == 0) return 0;
        h = grid.length;
        w = grid[0].length;
        visited = new boolean[h][w];
        Arrays.stream(visited).forEach(row -> Arrays.fill(row, false));
        int maxArea = 0;
        for(int r = 0; r < h; ++r) {
            for(int c = 0; c < w; ++c) {
                if(grid[r][c] == 1 && !visited[r][c]) {
                    area = 0;
                    dfs(grid, r, c);
                    maxArea = Math.max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
    private void dfs(int[][] grid, int r, int c) {
        area += 1;
        visited[r][c] = true;
        if(r > 0 && grid[r - 1][c] == 1 && !visited[r - 1][c]) dfs(grid, r - 1, c);
        if(c > 0 && grid[r][c - 1] == 1 && !visited[r][c - 1]) dfs(grid, r, c - 1);
        if(r < h - 1 && grid[r + 1][c] == 1 && !visited[r + 1][c]) dfs(grid, r + 1, c);
        if(c < w - 1 && grid[r][c + 1] == 1 && !visited[r][c + 1]) dfs(grid, r, c + 1);
    }
}
