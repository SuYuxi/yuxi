class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> stack = new Stack();
        int[] ans = new int[temperatures.length];
        for(int inx = 0; inx < temperatures.length; ++inx) {
            while(!stack.empty() && temperatures[inx] > temperatures[stack.peek()]) {
                int preInx = stack.pop();
                ans[preInx] = inx - preInx;
            }
            stack.push(inx);
        }
        return ans;
    }
}
