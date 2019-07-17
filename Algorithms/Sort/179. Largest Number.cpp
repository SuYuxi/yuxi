class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStr;
        for(int& num : nums)
        {
            numStr.emplace_back(to_string(num));
        }
        sort(numStr.begin(), numStr.end(), cmp);
        string res;
        for(string& s : numStr) res += s;
        if(res[0] == '0') return "0";
        return res;
    }
private:
    static bool cmp(string& a, string& b) {
        return a + b > b + a;
    } 
};
