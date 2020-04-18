class Solution {
public:
    string getHappyString(int n, int k) {
        int curNum = k;
        return backtrack(n, curNum, 0, 0);
    }
    string backtrack(int n, int& k, char preChar, int len) {
        if(len == n)
        {
            k -= 1;
            return "";
        }
        for(char c = 'a'; c <= 'c'; ++c)
        {
            if(c != preChar)
            {
                string res = backtrack(n, k, c, len + 1);
                if(k == 0)
                {
                    return string(1, c) + res;
                }
            }
        }
        return "";
    }
};
