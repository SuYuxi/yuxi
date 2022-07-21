class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        for(int inx = 0, preSum = 0; inx < nums.length; ++inx) {
            if(preSum == sum - preSum - nums[inx]) return inx;
            preSum += nums[inx];
        }
        return -1;
    }
}
