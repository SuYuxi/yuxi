class Solution {
    public String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0")) return "0";
        
        StringBuilder firstNumber = new StringBuilder(num1);
        StringBuilder secondNumber = new StringBuilder(num2);
        
        firstNumber.reverse();
        secondNumber.reverse();
        
        int N = firstNumber.length() + secondNumber.length();
        StringBuilder answer = new StringBuilder();
        for(int i = 0; i < N; ++i) {
            answer.append(0);
        }
        
        for(int place1 = 0; place1 < firstNumber.length(); ++place1) {
            int digit1 = firstNumber.charAt(place1) - '0';
            for(int place2 = 0; place2 < secondNumber.length(); ++place2) {
                int digit2 = secondNumber.charAt(place2) - '0';
                int curPos = place1 + place2;
                int carry = answer.charAt(curPos) - '0';
                int mul = digit1 * digit2 + carry;
                
                answer.setCharAt(curPos, (char)(mul % 10 + '0'));
                int val = (answer.charAt(curPos + 1) - '0') + mul / 10;
                answer.setCharAt(curPos + 1, (char)(val + '0'));
            }
        }
        if(answer.charAt(answer.length() - 1) == '0') {
            answer.deleteCharAt(answer.length() - 1);
        }
        answer.reverse();
        return answer.toString();
    }
}
