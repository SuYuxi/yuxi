class Solution {
public:
    int maxPower(string s) {
        if(s.empty()) return 0;
        int power = 1;
        int cur = 1;
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i] == s[i - 1])
            {
                cur += 1;                
            }
            else 
            {
                power = max(power, cur);
                cur = 1;
            }
        }
        return max(power, cur);
    }
};
