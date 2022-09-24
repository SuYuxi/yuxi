class Solution {
    public int makeConnected(int n, int[][] connections) {
        if(n - 1 > connections.length) return -1;
        int[] parents = new int[n];
        for(int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        for(int[] conn : connections) {
            parents[find(parents, conn[0])] = find(parents, conn[1]);    
        }
        int clusters = 0;
        for(int i = 0; i < n; ++i) {
            if(find(parents, i) == i) clusters += 1;
        }
        return clusters - 1;
    }
    
    private int find(int[] parents, int pos) {
        if(parents[pos] != pos) {
            parents[pos] = find(parents, parents[pos]);
        }
        return parents[pos];
    }
}
