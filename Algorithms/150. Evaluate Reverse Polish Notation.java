class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack();
        int a, b, value = 0;
        for(String token : tokens) {
            switch(token) {
                case("/"):
                    b = stack.pop();
                    a = stack.pop();
                    value = a / b;
                    break;
                case("*"):
                    b = stack.pop();
                    a = stack.pop();
                    value = a * b;
                    break;
                case("+"):
                    b = stack.pop();
                    a = stack.pop();
                    value = a + b;
                    break;
                case("-"):
                    b = stack.pop();
                    a = stack.pop();
                    value = a - b;
                    break;
                default:
                    value = Integer.valueOf(token);
            }
            stack.push(value);
        }
        return stack.pop();
    }
}
