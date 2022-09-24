class Solution {
    int[] parents;
    public int findCircleNum(int[][] isConnected) {
        int len = isConnected.length;
        parents = new int[len];
        for(int i = 0; i < len; ++i) parents[i] = i;
        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                if(isConnected[i][j] == 1) {
                    parents[find(i)] = find(j);
                }
            }
        }
        int num = 0;
        for(int i = 0; i < len; ++i) {
            if(i == find(i)) ++num;
        }
        return num;
    }
    
    private int find(int pos) {
        if(parents[pos] != pos) {
            parents[pos] = find(parents[pos]);
        }
        return parents[pos];
    }
}
