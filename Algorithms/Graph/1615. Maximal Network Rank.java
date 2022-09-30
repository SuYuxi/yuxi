class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        int[] degree = new int[n];
        Set<Pair<Integer, Integer>> conn = new HashSet();
        for(int[] road : roads) {
            degree[road[0]] += 1;
            degree[road[1]] += 1;
            conn.add(new Pair(Math.min(road[0], road[1]), Math.max(road[0], road[1])));
        }
        int max = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int rank = degree[i] + degree[j];
                if(conn.contains(new Pair(i, j))) rank -= 1;
                max = Math.max(max, rank);
            }
        }
        return max;
    }
}
