class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> count(n, 1);
        vector<int> prev(n, -1);
        int maxLen = 0, maxInx = -1;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] % nums[j] == 0 && count[i] < count[j] + 1) 
                {
                    count[i] = count[j] + 1;
                    prev[i] = j;
                }
                else if(nums[i] / nums[j] < 2) break;
            }
            if(maxLen < count[i])
            {
                maxLen = count[i];
                maxInx = i;
            }
        }

        vector<int> ans(maxLen);
        int inx = maxInx;
        for(int i = maxLen - 1; i >= 0; --i)
        {
            ans[i] = nums[inx];
            inx = prev[inx];
        }
        return ans;
    }
};
