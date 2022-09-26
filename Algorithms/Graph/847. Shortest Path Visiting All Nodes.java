class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        int[][] dist = new int[n][1 << n];
        Queue<int[]> queue = new LinkedList();
        for(int i = 0; i < n; ++i) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
            dist[i][1 << i] = 0;
            queue.add(new int[]{i, 1 << i});
        }
        while(!queue.isEmpty()) {
            int[] state = queue.poll();
            int cur = state[0];
            int path = state[1];
            int d = dist[cur][path];
            for(int next : graph[cur]) {
                int newPath = path | (1 << next);
                if(d + 1 < dist[next][newPath]) {
                    dist[next][newPath] = d + 1;
                    queue.add(new int[]{next, newPath});
                }
            }
        }
        int res = Integer.MAX_VALUE;
        for(int i = 0; i < n; ++i) {
            res = Math.min(res, dist[i][(1 << n) - 1]);
        }
        
        return res;
    }
}
