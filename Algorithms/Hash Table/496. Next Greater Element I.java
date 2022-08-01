class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] res = new int[nums1.length];
        HashMap<Integer, Integer> hash = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        for(int num : nums2) {
            while(!stack.empty() && num > stack.peek()) {
                hash.put(stack.pop(), num);
            }
            stack.push(num);
        }
        
        for(int inx = 0; inx < nums1.length; ++inx) {
            res[inx] = hash.getOrDefault(nums1[inx], -1);
        }
        return res;
    }
}
