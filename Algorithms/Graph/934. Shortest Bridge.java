class Solution {
    int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    Queue<int[]> queue;
    public int shortestBridge(int[][] grid) {
        queue = new LinkedList();
        int h = grid.length, w = grid[0].length;
        int color = 2;
        boolean found = false;
        for(int r = 0; r < h; ++r) {
            for(int c = 0; c < w; ++c) {
                if(grid[r][c] == 1) {
                    dfs(grid, r, c, color);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        int number = -1;
        while(!queue.isEmpty()) {
            ++number;
            int size = queue.size();
            for(int i = 0; i < size; ++i) {
                int[] pos = queue.poll();
                for(int[] dir : dirs) {
                    int nr = pos[0] + dir[0], nc = pos[1] + dir[1];
                    if(nr >= 0 && nr < h && nc >= 0 && nc < w) {
                        if(grid[nr][nc] == 1) return number;
                        if(grid[nr][nc] == 0) {
                            grid[nr][nc] = 2;
                            queue.offer(new int[]{nr, nc});
                        }
                    }
                }
            }
        }
        return -1;
        
    }
    private void dfs(int[][] grid, int r, int c, int color) {
        if(r >= 0 && r < grid.length && c >= 0 && c < grid[0].length && grid[r][c] == 1) {
            queue.offer(new int[]{r, c});
            grid[r][c] = color;
            for(int[] dir : dirs) dfs(grid, r + dir[0], c + dir[1], color);
        }
        return;
    }
}
