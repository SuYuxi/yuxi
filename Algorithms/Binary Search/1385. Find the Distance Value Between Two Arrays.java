class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        int inx = 0, res = 0;
        for(int num : arr1) {
            for(; inx < arr2.length && num > arr2[inx]; ++inx);
            if((inx == arr2.length || num < arr2[inx] - d) && (inx == 0 || num > arr2[inx - 1] + d)) ++res;
        }
        return res;
    }
}
