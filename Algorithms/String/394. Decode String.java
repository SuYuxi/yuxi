class Solution {
    public String decodeString(String s) {
        Stack<String> stack = new Stack();
        String cur = "", num = "";
        
        for(int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if(Character.isDigit(c)) {
                num += c;
            }
            else if(c == '[') {
                stack.push(cur);
                stack.push(num);
                num = "";
                cur = "";
            }
            else if(c == ']') {
                int count = Integer.parseInt(stack.pop());
                String pre = stack.pop();
                cur = cur.repeat(count);
                cur = pre + cur;
            }
            else {
                cur += c;
            }
        }
        return cur;
    }
}
