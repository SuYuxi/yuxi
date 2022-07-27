class Solution {
    public int closedIsland(int[][] grid) {
        if(grid.length == 0) return 0;
        int h = grid.length, w = grid[0].length;
        int[] dr = {-1, 0, 1, 0};
        int[] dc = {0, -1, 0, 1};
        boolean[][] visited = new boolean[h][w];
        Arrays.stream(visited).forEach(row -> Arrays.fill(row, false));
        int closedIslands = 0;
        for(int r = 1; r < h - 1; ++r) {
            for(int c = 1; c < w - 1; ++c) {
                if(grid[r][c] == 0 && !visited[r][c]) {
                    Stack<int[]> stack = new Stack();
                    stack.push(new int[]{r, c});
                    visited[r][c] = true;
                    boolean closed = true;
                    while(!stack.empty()) {
                        int[] p = stack.pop();
                        int cr = p[0], cc = p[1];
                        for(int k = 0; k < 4; ++k) {
                            int nr = cr + dr[k], nc = cc + dc[k];
                            if(grid[nr][nc] == 0 && !visited[nr][nc]) {
                                if(nr == 0 || nc == 0 || nr == h - 1 || nc == w - 1) {
                                    closed = false;
                                }
                                else {
                                    stack.push(new int[]{nr, nc});
                                    visited[nr][nc] = true;
                                }
                            }
                        }
                    }
                    if(closed) closedIslands += 1;
                }
            }
        }
        return closedIslands;
    }
}
