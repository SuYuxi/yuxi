class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] colors = new int[n];
        for(int i = 0; i < n; ++i) {
            if(colors[i] == 0) {
                colors[i] = 1;
                if(!dfs(graph, colors, i)) return false;
            }
        }
        return true;
    }

    private boolean dfs(int[][] graph, int[] colors, int pos) {
        for(int next : graph[pos]) {
            if(colors[next] == colors[pos]) return false;
            if(colors[next] == 0) {
                colors[next] = 3 - colors[pos];
                if(!dfs(graph, colors, next)) return false;
            }
        }
        return true;
    }
}
