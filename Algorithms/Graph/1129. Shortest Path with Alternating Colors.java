class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] red_edges, int[][] blue_edges) {
        Set<Integer>[][] graph = new HashSet[2][n];
        int[][] steps = new int[2][n];
        for (int i = 0; i < n; i++) {
            graph[0][i] = new HashSet<>();
            graph[1][i] = new HashSet<>();
        }
        for(int i = 0; i < 2; ++i) {
            Arrays.fill(steps[i], 2 * n);
        }
        steps[0][0] = 0;
        steps[1][0] = 0;
        for(int[] edge : red_edges) {
            graph[0][edge[0]].add(edge[1]);
        }
        for(int[] edge : blue_edges) {
            graph[1][edge[0]].add(edge[1]);
        }

        Queue<int[]> queue = new LinkedList();
        queue.add(new int[]{0, 0});
        queue.add(new int[]{0, 1});
        while(!queue.isEmpty()) {
            int[] node = queue.poll();
            int cur = node[0];
            int color = node[1];
            for(int next : graph[color][cur]) {
                if(steps[1 - color][next] == 2 * n) {
                    queue.add(new int[]{next, 1 - color});
                    steps[1 - color][next] = steps[color][cur] + 1;
                }
            }
        }
        int[] res = new int[n];
        for(int i = 0; i < n; ++i) {
            int t = Math.min(steps[0][i], steps[1][i]);
            res[i] = (t == 2 * n) ? -1 : t;
        }
        return res;
    }
}
