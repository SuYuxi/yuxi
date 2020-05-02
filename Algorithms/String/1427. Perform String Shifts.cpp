class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        if(s.empty()) return s;
        int size = s.size();
        int leftShift = 0;
        for(vector<int>& s : shift)
        {
            leftShift += (s[0] == 0 ? s[1] : -s[1]); 
        }
        leftShift %= size;
        if(leftShift < 0)
        {
            leftShift += size;
        }
        return s.substr(leftShift) + s.substr(0, leftShift);
    }
};
