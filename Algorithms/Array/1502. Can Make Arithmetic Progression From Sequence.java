class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE, n = arr.length;
        for (int num : arr) {
            min = Math.min(min, num);
            max = Math.max(max, num);
        }
        if ((max - min) % (n - 1) != 0) return false;
        int step = (max - min) / (n - 1);
        if (step == 0) return true;  // [0, 0, 0]
        Set<Integer> set = new HashSet<>();
        for (int num : arr) {
            if ((num - min) % step != 0) return false;
            if (!set.add(num)) return false;
        }
        return true;
    }
}
