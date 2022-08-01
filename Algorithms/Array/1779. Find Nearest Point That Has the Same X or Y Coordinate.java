class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int dist = Integer.MAX_VALUE;
        int inx = -1;
        for(int i = 0; i < points.length; ++i) {
            if(points[i][0] == x || points[i][1] == y) {
                int d = Math.abs(points[i][0] - x) + Math.abs(points[i][1] - y);
                if(dist > d) {
                    dist = d;
                    inx = i;
                }
            }
        }
        return inx;
    }
}
