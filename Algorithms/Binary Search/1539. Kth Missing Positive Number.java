class Solution {
    public int findKthPositive(int[] arr, int k) {
        int left = 0, right = arr.length;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] - mid - 1 < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return k + left;
    }
}
