class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        int h = maze.length, w = maze[0].length;
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        Queue<int[]> queue = new LinkedList();
        queue.offer(entrance);
        maze[entrance[0]][entrance[1]] = '+';
        int step = 0;
        while(!queue.isEmpty()) {
            ++step;
            int size = queue.size();
            for(int i = 0; i < size; ++i) {
                int[] pos = queue.poll();
                for(int[] dir : dirs) {
                    int nr = pos[0] + dir[0], nc = pos[1] + dir[1];
                    if(nr >= 0 && nr < h && nc >= 0 && nc < w && maze[nr][nc] == '.') {
                        if(nr == 0 || nr == h - 1 || nc == 0 || nc == w - 1) return step;
                        queue.offer(new int[]{nr, nc});
                        maze[nr][nc] = '+';
                    }
                }
            }
        }
        return -1;
    }
}
