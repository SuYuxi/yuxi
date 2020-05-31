class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(pow(2, k) > s.size() - k + 1) return false;
        vector<bool> found(1 << k, false);
        int mask = (1 << k) - 1;
        int cnt = 0;
        for(int i = 0, num = 0; i <= s.size(); ++i)
        {
            num = mask & ((num << 1) + s[i] - '0');
            if(i >= k - 1)
            {
                if(!found[num])
                {
                    cnt += 1;
                    found[num] = true;
                }
            }
        }
        return cnt == (1 << k);
    }
};
