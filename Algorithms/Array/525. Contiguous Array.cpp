class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int, int> hash;
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            cnt += (nums[i] == 1 ? 1 : -1);
            if(cnt == 0)
            {
                res = i + 1;
            }
            else
            {
                if(hash.count(cnt) == 0) hash[cnt] = i;
                else res = max(res, i - hash[cnt]);
            }
        }
        return res;
    }
};
