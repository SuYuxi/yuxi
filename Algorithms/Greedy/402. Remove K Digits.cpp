class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;
        for(char& c : num)
        {
            while(k > 0 && !stack.empty() && c < stack.back())
            {
                stack.pop_back();
                k -= 1;
            }
            stack.push_back(c);
        }
        while(k > 0)
        {
            stack.pop_back();
            k -= 1;
        };
        stack.erase(0, stack.find_first_not_of("0"));
        return stack.empty() ? "0" : stack;
    }
};
