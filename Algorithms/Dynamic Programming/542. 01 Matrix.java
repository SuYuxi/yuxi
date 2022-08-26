class Solution {
    public int[][] updateMatrix(int[][] mat) {
        if(mat.length == 0) return mat;
        int h = mat.length, w = mat[0].length;
        int[][] dist = new int[h][w];
        for(int i = 0; i < h; ++i) Arrays.fill(dist[i], Integer.MAX_VALUE - 1);
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                }
                else {
                    if(i > 0) dist[i][j] = Math.min(dist[i][j], dist[i - 1][j] + 1);
                    if(j > 0) dist[i][j] = Math.min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }
        
        for(int i = h - 1; i >= 0; --i) {
            for(int j = w - 1; j >= 0; --j) {
                if(i < h - 1) dist[i][j] = Math.min(dist[i][j], dist[i + 1][j] + 1);
                if(j < w - 1) dist[i][j] = Math.min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
        return dist;
    }
}
