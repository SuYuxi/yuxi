class Solution {
    public boolean possibleBipartition(int n, int[][] dislikes) {
        List<Integer>[] graph = new ArrayList[n];
        for(int i = 0; i < n; ++i) graph[i] = new ArrayList<Integer>();
        int[] colors = new int[n];
        for(int[] dislike : dislikes) {
            graph[dislike[0] - 1].add(dislike[1] - 1);
            graph[dislike[1] - 1].add(dislike[0] - 1);
        }
        for(int i = 0; i < n; ++i) {
            if(colors[i] == 0) {
                colors[i] = 1;
                if(!dfs(graph, colors, i)) return false;
            }
        }
        return true;
    }

    private boolean dfs(List<Integer>[] graph, int[] colors, int pos) {
        for(int next : graph[pos]) {
            if(colors[next] == colors[pos]) return false;
            if(colors[next] == 0) {
                colors[next] = 3 - colors[pos];
                if(!dfs(graph, colors, next, colors[next])) return false;
            }
        }
        return true;
    }
}
