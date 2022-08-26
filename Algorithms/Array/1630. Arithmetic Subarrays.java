class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> res = new ArrayList();
        for(int i = 0; i < l.length; ++i) {
            res.add(isArithmetic(nums, l[i], r[i]));
        }
        return res;
    }
    
    private boolean isArithmetic(int[] nums, int l, int r) {
        if(r - l < 2) return true;
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        Set<Integer> set = new HashSet();
        for(int i = l; i <= r; ++i) {
            min = Math.min(min, nums[i]);
            max = Math.max(max, nums[i]);
            set.add(nums[i]);
        }
        if((max - min) % (r - l) != 0) return false;
        int interval = (max - min) / (r - l);
        for(int i = 1; i < r - l; ++i) {
            if(!set.contains(min + i * interval)) return false;
        }
        return true;
    }
}
