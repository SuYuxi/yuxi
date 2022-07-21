class Solution {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while(left <= right) {
            int pivot = left + (right - left) / 2;
            int num = nums[pivot];
            if(num == target) return pivot;
            if(num < target) left = pivot + 1;
            else right = pivot - 1;
        }
        return -1;
    }
}
