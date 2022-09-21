class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int h = grid.length, w = grid[0].length;
        if(grid[0][0] != 0 || grid[h - 1][w - 1] != 0) return -1;
        int[][] dirs = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
        Queue<int[]> q = new LinkedList();
        q.offer(new int[]{0, 0});
        int length = 0;
        while(!q.isEmpty()) {
            int size = q.size();
            length += 1;
            for(int i = 0; i < size; ++i) {
                int[] pos = q.poll();
                if(pos[0] == h - 1 && pos[1] == w - 1) return length;
                for(int[] dir : dirs) {
                    int nr = pos[0] + dir[0], nc = pos[1] + dir[1];
                    if(nr >= 0 && nr < h && nc >= 0 && nc < w && grid[nr][nc] == 0) {
                        q.offer(new int[]{nr, nc});
                        grid[nr][nc] = 1;
                    }
                }
            }
        }
        return -1;
    }
}
