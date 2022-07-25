class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int num = cost.length;
        int[] dp = new int[num];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int inx = 2; inx < num; ++inx) {
            dp[inx] = cost[inx] + Math.min(dp[inx - 1], dp[inx - 2]);
        }
        return Math.min(dp[num -1], dp[num - 2]);
    }
}
